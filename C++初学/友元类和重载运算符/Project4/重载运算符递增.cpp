#include<iostream>
using namespace std;
#include<string>
class A {
public:
	int num1 = 0;
	int num2 = 1;
	A& operator++() {
		num1++;
		num2++;
		return *this;
	}
	A operator++(int) {
		A temp;	
		temp = *this;
		this->num1++;
		this->num2++;
		return temp;
	}
};
ostream &operator<<(ostream& os,const A &a) {
	os << a.num1 << "\t";
	os << a.num2 << "\t";
	return os;
}
int main() {
	A a;
	cout << a << endl;
	a++;
	cout << a<< endl;
	++a;
	cout << a << endl;
	return 0;
}