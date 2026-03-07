#include<iostream>
using namespace std;
int main()
{
	for (int a = 7; a < 100; a++)
	{
		if (a % 7 == 0 || a / 10 == 7 || a % 10 == 7)
		{
			cout << a << endl;
		}
	}
	return 0;
}	