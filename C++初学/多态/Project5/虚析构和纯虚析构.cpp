#include <iostream>
using namespace std;

//============================================
// 案例1：虚析构（防止内存泄漏）
//============================================
class Animal {
public:
    // 虚析构（有函数体）
    virtual ~Animal() {
        cout << "Animal 虚析构" << endl;
    }

    virtual void speak() const = 0;
};

class Dog : public Animal {
private:
    int* age;  // 堆内存资源

public:
    Dog() {
        age = new int(5);
        cout << "Dog 构造，分配内存 age=" << *age << endl;
    }

    void speak() const override {
        cout << "汪汪汪" << endl;
    }

    ~Dog() {
        delete age;
        cout << "Dog 析构，释放内存" << endl;
    }
};

//============================================
// 案例2：纯虚析构（让类抽象，但必须实现）
//============================================
class Shape {
public:
    // 纯虚析构（声明）
    virtual ~Shape() = 0;

    virtual double area() const = 0;
};

// 纯虚析构必须类外实现！
Shape::~Shape() {
    cout << "Shape 纯虚析构" << endl;
}

class Circle : public Shape {
private:
    double* radius;  // 堆内存

public:
    Circle(double r) {
        radius = new double(r);
        cout << "Circle 构造，半径=" << *radius << endl;
    }

    double area() const override {
        return 3.14 * (*radius) * (*radius);
    }

    ~Circle() {
        delete radius;
        cout << "Circle 析构，释放半径内存" << endl;
    }
};

//============================================
// 案例3：不加虚析构（演示内存泄漏）
//============================================
class Base {
public:
    // 非虚析构（危险！）
    ~Base() {
        cout << "Base 非虚析构" << endl;
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int(100);
        cout << "Derived 构造，分配内存 data=" << *data << endl;
    }

    ~Derived() {
        delete data;
        cout << "Derived 析构，释放内存" << endl;
    }
};

//============================================
// 主函数测试
//============================================
int main() {
    cout << "========== 测试1：虚析构（正确） ==========" << endl;
    Animal* animal = new Dog();
    animal->speak();
    delete animal;  // Dog析构 → Animal析构
    cout << endl;

    cout << "========== 测试2：纯虚析构（正确） ==========" << endl;
    Shape* shape = new Circle(5);
    cout << "圆的面积: " << shape->area() << endl;
    delete shape;  // Circle析构 → Shape析构
    cout << endl;

    cout << "========== 测试3：非虚析构（内存泄漏） ==========" << endl;
    Base* base = new Derived();
    delete base;  // ❌ 只调Base析构，Derived析构没调！
    cout << "注意：Derived的data内存没释放！泄漏了" << endl;

    return 0;
}