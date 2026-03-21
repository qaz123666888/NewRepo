#include<iostream>
using namespace std;
#include<string>
#define people 10
class score {
public:
	friend score *test01();
	friend void print(score *number);
	score operator+(const score& s) {
		score result;
		result.chinese = this->chinese + s.chinese;
		result.english = this->english + s.english;
		result.math = this->math + s.math;
		return result;
	}
	void total() {
		cout << "总分" << chinese + english + math << endl;
	}
	void all() {
		score s;
		s.chinese = s.chinese + this->chinese;
		cout<< "总分" << s.chinese + this->english + this->math << endl;
	}
private:
	int chinese=0, english=0, math=0;
};
score *test01() {
	score *number=new score[people];
	srand(time(NULL));
	for (int i = 0; i < people;i++) {
		number[i].chinese = rand()%101;
		number[i].english = rand() % 101;
		number[i].math = rand() % 101;
	}
	return number;
}
void print(score *number) {
	cout << endl;
	score temp;
	for (int i = 0; i < people; i++) {
		cout << "第" << i + 1 << "个人的成绩：chinese:" << number[i].chinese << " english:" << number[i].english << " math:" << number[i].math << endl;
		number[i].total();
		temp = temp + number[i];
	}
	cout << "均分" << temp.chinese / people << " " << temp.english / people << " " << temp.math / people << endl;
}
int main() {
	score* number = test01();
	print(number);
	delete[] number;	
	system("pause");
	return 0;
}