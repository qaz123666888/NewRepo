#include<iostream>	
using namespace std;
template<typename T>
void myswap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

void test01() {
	// int 类型
	int c = 10;
	int d = 20;
	cout << "【int】交换前: c = " << c << ", d = " << d << endl;
	myswap(c, d);
	cout << "【int】交换后: c = " << c << ", d = " << d << endl;

	cout << "-----------------------" << endl;

	// double 类型
	double x = 3.14;
	double y = 2.718;
	cout << "【double】交换前: x = " << x << ", y = " << y << endl;
	myswap(x, y);
	cout << "【double】交换后: x = " << x << ", y = " << y << endl;

	cout << "-----------------------" << endl;

	// string 类型
	string s1 = "Hello";
	string s2 = "World";
	cout << "【string】交换前: s1 = " << s1 << ", s2 = " << s2 << endl;
	myswap(s1, s2);
	cout << "【string】交换后: s1 = " << s1 << ", s2 = " << s2 << endl;
}
int main() {
	test01();



}