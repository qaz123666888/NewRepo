#include <iostream>
using namespace std;

// 父类：动物
class Animal {
public:
    string name;
    void bark() { cout << "111"; }
    void eat() {
        cout << name << " 在吃东西" << endl;
    }
};

// 子类：狗，继承自动物       同时可以更改父类函数
class Dog : public Animal {
public:
    void bark() {
        cout << name << " 汪汪叫" << endl;
    }
};

//三种方式权限
class Father {
private:
    int money;      // 儿子不能直接拿
protected:
    int house;      // 儿子可以继承使用
public:
    int car;        // 谁都能用
};

class Son : public Father {
public:
    void test() {
        // money = 100;  ❌ 不能访问private
        house = 200;     // ✅ 可以访问protected
        car = 300;       // ✅ 可以访问public
    }
};


//析构顺序
class Base {
public:
    Base() { cout << "Base构造\n"; }
    ~Base() { cout << "Base析构\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived构造\n"; }
    ~Derived() { cout << "Derived析构\n"; }
};
// 输出：
// Base构造    (先构造父类)
// Derived构造 (再构造子类)
// Derived析构 (先析构子类)
// Base析构    (再析构父类)

int main() {
    Dog d;
    d.name = "小黑";    // 从父类继承的
    d.eat();           // 从父类继承的
    d.bark();          // 自己的
    Derived dd;
}