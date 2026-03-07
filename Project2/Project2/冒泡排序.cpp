#include<iostream>
using namespace std;
int main() {
	int arr[9] = { 4,2,8,0,5,7,1,3,9 },a;
	for (int i = 0; i < 9-1; i++) {
		for (int j = 0; j < 9 - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;
			}
		}
	}
	for (int k = 0; k < 9; k++) {
		cout << arr[k] << endl;
	}
	return 0;
}