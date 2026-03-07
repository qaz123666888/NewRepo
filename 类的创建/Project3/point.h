#pragma once
#include<iostream>
using namespace std;
class point {
public:
	//设置点
	void setpoint(int x1, int y1);
	//获取点x
	int getpointx();
	//获取点y
	int getpointy();
private:
	int x, y;
};