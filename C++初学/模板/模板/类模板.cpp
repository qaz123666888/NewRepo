#include <iostream>
using namespace std;

template<typename T>
class Counter {
public:
    static int count;  // 每个T有自己的count
    Counter() { count++; }
    ~Counter() { count--; }

    // 可添加获取count的静态函数
    static int getCount() { return count; }
};

// 模板静态成员初始化
template<typename T>
int Counter<T>::count = 0;

int main() {
    Counter<int> c1, c2, c3;
    Counter<double> d1, d2;

    cout << "int数量: " << Counter<int>::count << endl;      // 3
    cout << "double数量: " << Counter<double>::count << endl; // 2
    cout << "int数量(get函数): " << Counter<int>::getCount() << endl; // 3

    {
        Counter<int> c4, c5;  // 局部作用域
        cout << "作用域内int数量: " << Counter<int>::count << endl; // 5
    }  // c4,c5析构

    cout << "作用域外int数量: " << Counter<int>::count << endl; // 3

    return 0;
}