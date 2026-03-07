#include<iostream>
using namespace std;
int main()
{
	int a=100,b,c,d;
	while (a < 1000)
	{
		b = a / 100;
		c =( a / 10) % 10;
		d = a % 10;
		if (c*c*c+b*b*b+d*d*d==a) {
			   cout << a << endl;
		}
		a++;
	}
	return 0;
}