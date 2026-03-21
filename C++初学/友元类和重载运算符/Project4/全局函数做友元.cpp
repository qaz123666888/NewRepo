#include <iostream>
using namespace std;
#include<string>
class building {
public:
	friend void test01();
	building() {
		sittingroom = "客厅";
		bedroom = "卧室";
	}
	string sittingroom;
private:
	string bedroom;

};
void test01() {
	building b;
	cout << 111 << b.sittingroom <<222<<b.bedroom<< endl;
}
int main() {
	test01();
	system("pause");
	return 0;	

}