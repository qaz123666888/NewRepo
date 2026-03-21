#include <iostream>
using namespace std;

int main() {
    cout << "这行可能不会立即显示";  // 存在缓冲区
    cerr << "错误！这行立即显示";// 无缓冲，直接输出
    
    // 程序崩溃时，cout 的内容可能丢失
    // cerr 的内容一定会显示
    return 0;
}