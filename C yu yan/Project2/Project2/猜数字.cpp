#include<iostream>
#include<ctime>
using namespace std;
int main() 
{
	srand((int) time(NULL));
	int r,a=-1;
	r = rand() % 100;
	while (1)
	{
		cin >> a;
		if (a > r) {
			cout << "大" << endl;
		}
		else if (a < r) {
			cout << "小" << endl;
		}
		else {
			cout << "yes" << endl;
		}
	}
	return 0;
}