#pragma once
#include"point.h"
using namespace std;
class circle{
public:
	//设置圆心
	void setpointo(point o1);
		//获取圆心
		point getpointo();
		//设置半径
		void setr(int r1);
		//获取半径
		int getr();
private:
	point o;
	int r;
};