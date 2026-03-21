#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// ==================== 1. 类模板继承类模板 ====================
template <typename T>
class Base1 {
protected:
    T data;
public:
    Base1(T val) : data(val) {}

    void showData() {
        cout << "Base1 data: " << data << endl;
    }
};

template<typename T>
class Derived1 : public Base1<T> {  // 注意：必须写 Base1<T>
private:
    T extra;
public:
    Derived1(T val1, T val2) : Base1<T>(val1), extra(val2) {}

    void showAll() {
        // this->data    // ⚠️ 必须用 this-> 或 Base1<T>::
        cout << "Derived1 extra: " << extra << endl;
        this->showData();  // ✅ 通过this调用基类成员
    }
};

// ==================== 2. 类模板继承普通类 ====================
class NormalBase {
protected:
    int id;
public:
    NormalBase(int i) : id(i) {}
    void showId() { cout << "ID: " << id << endl; }
};

template<typename T>
class Derived2 : public NormalBase {
private:
    T value;
public:
    Derived2(int i, T v) : NormalBase(i), value(v) {}

    void showAll() {
        showId();           // ✅ 直接调用普通基类方法
        cout << "Value: " << value << endl;
    }
};

// ==================== 3. 普通类继承类模板 ====================
template<typename T>
class Base3 {
protected:
    T data;
public:
    Base3(T d) : data(d) {}
    virtual void print() { cout << "Base3: " << data << endl; }
};

class Derived3 : public Base3<int> {  // ⚠️ 必须指定具体类型
private:
    string name;
public:
    Derived3(int d, string n) : Base3<int>(d), name(n) {}

    void print() override {  // 虚函数重写
        cout << "Derived3: " << data << ", name: " << name << endl;
    }
};

// ==================== 4. CRTP（奇异递归模板模式） ====================
template<typename Derived>
class Shape {
public:
    void draw() {
        static_cast<Derived*>(this)->drawImpl();  // 调用派生类实现
    }

    // 提供默认实现（可选）
    void drawImpl() { cout << "Drawing Shape" << endl; }
};

class Circle : public Shape<Circle> {
public:
    void drawImpl() {  // 覆盖基类行为
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape<Rectangle> {
    // 使用默认实现，不重写
};

// ==================== 5. 模板模板参数继承 ====================
template<typename T, template<typename> class Container>
class Stack : public Container<T> {  // 继承自容器（如vector）
public:
    void push(const T& val) {
        this->push_back(val);  // 调用容器的push_back
    }

    T pop() {
        T val = this->back();
        this->pop_back();
        return val;
    }
};

// ==================== 6. 多继承与模板 ====================
template<typename T, typename U>
class MultiBase1 {
protected:
    T t;
public:
    MultiBase1(T val) : t(val) {}
};

template<typename T, typename U>
class MultiBase2 {
protected:
    U u;
public:
    MultiBase2(U val) : u(val) {}
};

template<typename T, typename U>
class MultiDerived : public MultiBase1<T, U>, public MultiBase2<T, U> {
public:
    MultiDerived(T tVal, U uVal)
        : MultiBase1<T, U>(tVal), MultiBase2<T, U>(uVal) {}

    void show() {
        cout << "t: " << this->t << ", u: " << this->u << endl;  // ⚠️ this-> 解决二义性
    }
};

// ==================== 7. 模板虚函数（演示限制） ====================
class VirtualDemoBase {
public:
    virtual void normalFunc() = 0;
    // template<typename T>           // ❌ 虚函数不能是模板
    // virtual void templateFunc(T t) {}
};

template<typename T>
class VirtualDemoDerived : public VirtualDemoBase {
private:
    T data;
public:
    VirtualDemoDerived(T d) : data(d) {}

    void normalFunc() override {  // 实现普通虚函数
        cout << "Data: " << data << endl;
    }
};

// ==================== 8. 友元与继承 ====================
template<typename T>
class WithFriend {
private:
    T secret;
public:
    WithFriend(T s) : secret(s) {}

    template<typename U>
    friend class FriendClass;  // 友元模板
};

template<typename T>
class FriendClass : public WithFriend<T> {  // 继承自友元类
public:
    FriendClass(T val) : WithFriend<T>(val) {}

    void reveal() {
         cout << this->secret; 
    }
};

// ==================== 测试代码 ====================
int main() {
    cout << "=== 1. 类模板继承类模板 ===" << endl;
    Derived1<int> d1(10, 20);
    d1.showAll();

    cout << "\n=== 2. 类模板继承普通类 ===" << endl;
    Derived2<double> d2(100, 3.14);
    d2.showAll();

    cout << "\n=== 3. 普通类继承类模板 ===" << endl;
    Derived3 d3(42, "Answer");
    d3.print();

    cout << "\n=== 4. CRTP模式 ===" << endl;
    Circle c;
    Rectangle r;
    c.draw();  // Drawing Circle
    r.draw();  // Drawing Shape（默认实现）

    cout << "\n=== 5. 模板模板参数 ===" << endl;
    Stack<int, vector> s;
    s.push(1);
    s.push(2);
    cout << "Pop: " << s.pop() << endl;

    cout << "\n=== 6. 多继承模板 ===" << endl;
    MultiDerived<int, double> md(5, 3.14);
    md.show();

    cout << "\n=== 7. 模板与虚函数 ===" << endl;
    VirtualDemoDerived<string> vd("Hello");
    vd.normalFunc();
    cout<<"111111111111111111111111111"<<endl;
    FriendClass<int> fc(42);
    fc.reveal();  // 输出：42 ✅
    return 0;
    return 0;
}