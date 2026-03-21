#pragma once  // 写在文件最开头（VS专用，更简单）
#include<iostream>
using namespace std;
#include<string>
template<typename T>
class myarray {

public:
	//有参构造 传入容量 
	myarray(int capacity){
		cout <<" 有参构造，构造函数生效" << endl;
		this->my_capacity = capacity;
		this->my_address =new T[this->my_capacity] ;
		this->my_size = 0;
	}


	//深拷贝（避免浅拷贝）
	myarray(const myarray & arr) {
		cout << " 深拷贝生效" << endl;
		this->my_capacity = arr.my_capacity;
		this->my_size = arr.my_size;
		this->my_address = new T[arr.my_capacity];
		for (int i = 0; i < arr.my_size; i++)
		{
			this->my_address[i] = arr.my_address[i];
		}
	}
	//重载赋值运算符
	myarray &operator=(const myarray& myarr) {
		cout << " 重载赋值运算符生效" << endl;
		//先判断原堆区是否有数据，有则清空
		if (this == &myarr) return *this;
		if (this->my_address != nullptr)
		{
			delete[]this->my_address;
			this->my_address = nullptr;
			this->my_size = 0;
			this->my_capacity = 0;
		}
		//深拷贝
		this->my_capacity = myarr.my_capacity;
		this->my_size = myarr.my_size;
		this->my_address = new T[this->my_capacity];  // 必须有！
		for (int i = 0; i < myarr.my_size; i++)
		{
			this->my_address[i] = myarr.my_address[i];
		}
		return *this;
	}

	//尾插法
	void push_back(T  val)
	{
		if (this->my_size == this->my_capacity)
		{
			return;
		}
		this->my_address[this->my_size] = val;
		this->my_size++;
	}
	
	//尾删法
	void pop_back() {
		if (this->my_size == 0) { return; }
		this->my_size--;
	}

	//通过下标方式来访问数组
	T& operator[](int val) {
		return this->my_address[val];
	}
	//返回数组容量
	int showcapacity() const {
		return this->my_capacity;
	
	}
	//返回数组大小
	int showsize() const {
		return this->my_size;
	}


	//析构函数
	~myarray() {
		cout << " 析构函数生效" << endl;
		if (this->my_address != nullptr)
		{
			delete[] this->my_address;
			this->my_address = nullptr;
		}
	
	
	}






private:
	int my_size ;
	T* my_address=nullptr ;
	int my_capacity;




};

void test01();
void test02();