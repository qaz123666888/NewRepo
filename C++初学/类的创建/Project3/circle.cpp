#include"circle.h"
	//设置圆心
	void circle::setpointo(point o1) {
		o = o1;
	}
	//获取圆心	
	point circle::getpointo() {
		return o;
	}
	//设置半径
	void circle::setr(int r1) {
		r = r1;
	}
	//获取半径
	int circle::getr() {
		return r;
	}
