#include"func.h"
void isincircle(circle& o, point& p) {
	int a = (o.getpointo().getpointx() - p.getpointx()) * (o.getpointo().getpointx() - p.getpointx())
		+ (o.getpointo().getpointy() - p.getpointy()) * (o.getpointo().getpointy() - p.getpointy());
	int b = o.getr() * o.getr();
	if (a == b) { cout << "点在圆上" << endl; }
	if (a < b) { cout << "点在圆内" << endl; }
	if (a > b) { cout << "点在圆外" << endl; }
}