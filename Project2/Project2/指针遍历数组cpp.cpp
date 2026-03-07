#include<iostream>
using namespace std;
int main() {
	int arr[10] = { 0,1,2,888,4,5,6,7,8,9 };
	int* p = arr;
	int* q = &arr[0];
	for (int i = 0; i < 10; i++) {
		cout << "p " << *p << "\n";
		cout << "q " << *q << "\n";
		p++, q++;
	}
	return 0;
}