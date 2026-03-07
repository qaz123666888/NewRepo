#include"manager.h"
manager::manager(int id1, string name1, double idd1) {
	this->id = id1;
	this->name = name1;
	this->idd = idd1;
}
void manager::show_id() {
	cout << "职工编号" << this->id
		<< "\t职工姓名" << this->name
		<< "\t职工岗位" << this->idd
		<< "\t岗位职责：完成老板交代任务，并给员工安排任务" << endl;
}
string manager::getname() {
	return string("manager");
}
void manager::showidd() {
	cout << "部门为" << this->idd;
}
