#include<iostream>
using namespace std;
class A {
public:
	int a = 110;
	int b = 20;
};
ostream &operator<<(ostream& os, A& a) {
	os << a.a<<endl ;
	os << a.b;
	return os;
}
int main() {
	A a;
	cout << a.a << " " << a.b << endl;
	cout << a << endl; ;
	return 0;
}