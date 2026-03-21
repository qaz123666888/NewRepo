#include<iostream>
using namespace std;

class A {
public:
    bool operator==(const A&) { return true; }
};

int main() {
    A a, b;
    cout << (   a == b);
    return 0;
}