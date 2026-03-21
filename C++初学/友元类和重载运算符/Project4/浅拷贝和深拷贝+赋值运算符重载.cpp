#include <iostream>
using namespace std;

class Test {
public:
    int* data;  // 指针，指向一块动态内存

    // 1. 构造函数：创建对象时 new 一块内存
    Test(int val) {
        data = new int(val);  // 开内存，存数值
        cout << "构造：new 了一块内存\n";
    }

    // 2. 深拷贝构造函数（重点！）
    Test(const Test& other) {
        // 不开新内存就是浅拷贝，会崩溃
        // 深拷贝：重新 new，再拷贝值
        data = new int(*other.data);
        cout << "深拷贝构造：自己 new 了一块新内存\n";
    }

    // 3. 赋值运算符重载（重点！）
    Test& operator=(const Test& other) {
        // 防止自己 = 自己
        if (this == &other) {
            return *this;
        }

        // 先把自己原来的内存删掉，不然泄漏
        delete data;
        cout << "赋值：先 delete 旧内存\n";

        // 再 new 新内存，拷贝数据
        data = new int(*other.data);
        cout << "赋值：new 新内存并拷贝值\n";

        return *this;
    }

    // 4. 析构函数
    ~Test() {
        delete data;  // 释放自己的内存
        cout << "析构：delete 内存\n";
    }
};

int main() {
    Test a(10);        // 构造
    Test b (a);        // 深拷贝构造
    Test c(20);        // 构造
    c = a;             // 赋值运算符

    cout << *a.data << endl;
    cout << *b.data << endl;
    cout << *c.data << endl;

    return 0;
}