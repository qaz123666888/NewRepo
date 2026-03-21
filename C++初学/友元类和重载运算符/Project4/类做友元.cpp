#include <iostream>
#include<string>
using namespace std;
class building;
class good {
	public:
		good();
		~good();
		void visit();
		good(const good&) = delete;
		good& operator=(const good&) = delete;
private:
	building* building;
};


class building {
	friend class good;
public:
	building();
	string sittingroom;
private:
	string bedroom;
};
building::building() {
	sittingroom = "客厅";
	bedroom = "卧室";
}
good::good() {
	building = new class building;
}
good::~good() {
    delete building;
    building = nullptr;
}
void good::visit() {
	cout << 111 << building->sittingroom << 222 << building->bedroom << endl;
}
void text01() {
	good g;
	g.visit();	
	
}
int main() {
	text01();
	system("pause");
	return 0;	
}