#include<iostream>
using namespace std;	
class A {
public:
	A operator+(A& a) {
		A temp;
		temp.num1 = this->num1 + a.num1;
		temp.num2 = this->num2 + a.num2;
		return temp;
	}
	int num1;
	double num2;
};
int main() {
	A a1, a2, a3;
	a1.num1 = 10;
	a1.num2 = 3.14;
	a2.num1 = 20;
	a2.num2 = 2.71;
	a3 = a1 + a2;
	cout << "a3.num1=" << a3.num1 << endl;
	cout << "a3.num2=" << a3.num2 << endl;
	return 0;
}