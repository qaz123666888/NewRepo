#include<iostream>
using namespace std;
#include"circle.h"
#include"point.h"
#include"func.h"
int main() {
	circle r;
	point p1;
	point p;
	r.setr(10);		
	p1.setpoint(10, 0);
	r.setpointo(p1);
	p.setpoint(10, 10);
	isincircle(r, p);
	system("pause");
	return 0;
}