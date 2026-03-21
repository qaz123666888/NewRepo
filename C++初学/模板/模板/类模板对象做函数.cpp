#include <iostream>
#include <string>
using namespace std;

// 类模板
template<typename T>
class Box {
    T content;
public:
    Box(T c) : content(c) {}
    T get() { return content; }
};

// 1. 指定类型
void showInt(Box<int>& b) {
    cout << "int: " << b.get() << endl;
}

// 2. 参数模板化
template<typename T>
void showBox(Box<T>& b) {
    cout << "Box: " << b.get() << endl;
}

// 3. 完全模板化
template<typename T>
void showAny(T& obj) {
    cout << "Any: " << obj.get() << endl;
}

int main() {
    Box<int> iBox(100);
    Box<double> dBox(3.14);
    Box<string> sBox("Hello");

    // 方式1：只能传int
    showInt(iBox);      // ✅
    // showInt(dBox);   // ❌

    // 方式2：可以传任何Box
    showBox(iBox);      // ✅ T=int
    showBox(dBox);      // ✅ T=double
    showBox(sBox);      // ✅ T=string

    // 方式3：更通用
    showAny(iBox);      // ✅
    showAny(dBox);      // ✅
    showAny(sBox);      // ✅

    return 0;
}