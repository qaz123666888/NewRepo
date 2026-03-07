#include <iostream>
using namespace std;

// 抽象类：动物
class Animal {
public:
    virtual void speak() const = 0;  // 纯虚函数
    virtual void move() const = 0;
    virtual ~Animal() = default;

    void eat() const {  // 普通函数
        cout << "吃东西\n";
    }
};

// 子类必须实现所有纯虚函数
class Dog : public Animal {
public:
    void speak() const override {
        cout << "汪汪汪\n";
    }
    void move() const override {
        cout << "四条腿跑\n";
    }
};

class Bird : public Animal {
public:
    void speak() const override {
        cout << "叽叽喳喳\n";
    }
    void move() const override {
        cout << "飞\n";
    }
};

int main() {
    // Animal a;  // ❌ 不能创建抽象类对象

    Dog dog;
    Bird bird;

    Animal* animals[] = { &dog, &bird };

    for (auto a : animals) {
        a->speak();
        a->move();
        a->eat();
    }
}