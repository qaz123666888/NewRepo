#include <string>
#include <iostream>
using namespace std;

int main() {
    string s1 = "hello";        // 直接赋值
    string s2("world");         // 构造函数
    string s3(5, 'a');          // "aaaaa"

    // 像vector一样用
    cout << "size: " << s1.size() << endl;           // 长度：5
    cout << "empty: " << s1.empty() << endl;         // 是否为空
    cout << "first char: " << s1[0] << endl;         // 访问字符：'h'
    cout << "front: " << s1.front() << endl;         // 第一个字符
    cout << "back: " << s1.back() << endl;           // 最后一个字符

    // 字符串专有操作
    string s4 = s1 + s2;                              // 拼接
    cout << "s1 + s2: " << s4 << endl;               // "helloworld"

    s1.append(s2);                                    // 追加
    cout << "after append: " << s1 << endl;          // "helloworld"

   auto pos = s1.find("lo");                         // 查找子串
    if (pos != string::npos) {
        cout << "find 'lo' at: " << pos << endl;     // 位置
    }

    string sub = s1.substr(1, 5);                     // 取子串
    cout << "substr(1,5): " << sub << endl;          // "ell"

    return 0;  // 返回值：程序正常结束
}