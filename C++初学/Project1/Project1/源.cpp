#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class compare {
public:
	bool operator()(int val1,int val2) {
		cout<<"6" << endl;
		return val1 > val2;
	}

};
void test01() {
	vector<int>v;
	v.push_back(10);
	v.push_back(104);
	v.push_back(130);
	v.push_back(110);
	v.push_back(410);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	sort(v.begin(),v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	sort(v.begin(), v.end(), compare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}

}
int main() {
	test01();


}