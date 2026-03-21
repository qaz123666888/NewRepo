#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 抽象基类
class Operation {
public:
    virtual int getResult(int a, int b) const = 0;
    virtual ~Operation() = default;
};

// 四则运算类
class Add : public Operation {
public:
    int getResult(int a, int b) const override { return a + b; }
};

class Sub : public Operation {
public:
    int getResult(int a, int b) const override { return a - b; }
};

class Mul : public Operation {
public:
    int getResult(int a, int b) const override { return a * b; }
};

class Div : public Operation {
public:
    int getResult(int a, int b) const override {
        if (b == 0) throw "除数不能为0";
        return a / b;
    }
};

// 工厂类
class Factory {
public:
    static unique_ptr<Operation> create(char op) {
        switch (op) {
        case '+': return make_unique<Add>();
        case '-': return make_unique<Sub>();
        case '*': return make_unique<Mul>();
        case '/': return make_unique<Div>();
        default: return nullptr;
        }
    }
};

int main() {
    int a = 20, b = 4;
    string ops = "+-*/";

    for (char op : ops) {
        auto p = Factory::create(op);
        if (p) {
            cout << a << " " << op << " " << b << " = "
                << p->getResult(a, b) << endl;
        }
    }
}