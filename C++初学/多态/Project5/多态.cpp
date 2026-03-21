#include<iostream>
using namespace std;
class animal {
public:
	void virtual speak() {
		cout << "111" << endl;
	}
};
class dog :public animal {
	public:
	void speak() {
		cout << "222" << endl;
	}

};
void test01(animal &animal1) {
	 animal1.speak();
}
int main() {
	dog d;
	test01(d);
	system("pause");
}