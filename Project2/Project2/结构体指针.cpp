#include<iostream>
using namespace std;
#include<string>
typedef struct student {
	string name;
	int age;
	int score;
}stu,*s;
int main() {
	stu stu1 = { "张三",22,88};
	s p = &stu1;
	stu* q = &stu1;
	cout << p->name << "\t" << p->age << "\t" << p->score << endl;
	cout << q->name << "\t" << q->age << "\t" << q->score << endl;
	return 0;
}