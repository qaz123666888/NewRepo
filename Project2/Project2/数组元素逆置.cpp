#include<iostream>
using namespace std;
int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int start = 0, end = sizeof(arr) / sizeof(arr[0]) - 1,temp;
	while (start < end) {
		temp = arr[end];
		arr[end] = arr[start];
		arr[start] = temp;
		start++, end--;
	}
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}