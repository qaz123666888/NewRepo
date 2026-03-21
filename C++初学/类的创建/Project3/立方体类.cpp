#include<iostream>
using namespace std;
#include<string>
class cube {
public:
	//设置长
	void set_length(int l) {
		length = l;
	}

	//获取长
	int get_length() {
		return length;
	}
	//设置宽
	void set_wide(int w) {
		wide = w;
	}
	//获取宽
	int get_wide() {
		return wide;
	}
	//设置高
	void set_high(int h) {
		high = h;
	}
	//获取高
	int get_high() {
		return high;
	}
	//获取立方体面积
	int get_square() {
		return high * (wide + length) * 2 + length * wide * 2;
	}
	//获取立方体体积
	int get_cube() {
		return length * wide * high;
	}
	//判断是否相等
	bool issameq(cube &c) {
			if (c.get_high() != high || c.get_length() != length
				|| c.get_wide() != wide)
			{
				return false;
			}
			else { return true; }
		}	
private:
	int length;//长度
	int wide;//宽度
	int high;//高度 
};
bool issame(cube &c1,cube &c2) {
	if (c1.get_high() != c2.get_high() || c1.get_length() != c2.get_length()
		|| c1.get_wide() != c2.get_wide()) {
		return false;
	}
	else {
		return true;
	}
	}
int main()
{
	//创建第一个立方体对象
	cube c1;
	c1.set_high(10);
	c1.set_length(10);
	c1.set_wide(10);
	//创建第二个立方体对象
	cube c2;
	c2.set_high(10);
	c2.set_length(10);
	c2.set_wide(15);
	//cout<<"立方体面积为：" <<c1.get_square()<< endl;
	//cout << "立方体体积为：" << c1.get_cube() << endl;
	if (issame(c1, c2)) {
		cout << "两个立方体是相等的（全局）" << endl;
	}
	else {
		cout << "二者不同" << endl;
	}
	if (c2.issameq(c1)) {
		cout << "两个立方体是相等的（函数）" << endl;
	}
	else {
		cout << "二者不同" << endl;
	}
	
	system("pause");
	return 0;


}