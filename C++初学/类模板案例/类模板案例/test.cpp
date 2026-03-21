#pragma once 
#include"myarray.hpp"
#include<iostream>
#include<string>
using namespace std;
// test01：基本功能测试（int类型）
void test01() {
    cout << "========== test01：基本功能测试(int) ==========" << endl;

    // 1. 有参构造
    myarray<int> arr1(5);
    cout << "初始容量: " << arr1.showcapacity() << ", 大小: " << arr1.showsize() << endl;

    // 2. 尾插法
    for (int i = 0; i < 3; i++) {
        arr1.push_back(i * 10);
        cout << "插入 " << i * 10 << " 后，大小: " << arr1.showsize() << endl;
    }

    // 3. 下标访问和修改
    cout << "\n通过下标访问: ";
    for (int i = 0; i < arr1.showsize(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // 修改元素
    arr1[1] = 999;
    cout << "修改后: ";
    for (int i = 0; i < arr1.showsize(); i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // 4. 尾删法
    cout << "\n尾删前大小: " << arr1.showsize();
    arr1.pop_back();
    cout << "，尾删后大小: " << arr1.showsize() << endl;

    // 5. 拷贝构造（深拷贝测试）
    cout << "\n--- 拷贝构造测试 ---" << endl;
    myarray<int> arr2(arr1);  // 深拷贝
    cout << "arr2大小: " << arr2.showsize() << ", 元素: ";
    for (int i = 0; i < arr2.showsize(); i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // 修改arr1，验证深拷贝（arr2不受影响）
    arr1[0] = 888;
    cout << "修改arr1[0]=888后，arr1: " << arr1[0] << ", arr2: " << arr2[0] << " (深拷贝验证)" << endl;

    // 6. 赋值运算符测试
    cout << "\n--- 赋值运算符测试 ---" << endl;
    myarray<int> arr3(5);  // 容量5
    arr3.push_back(100);
    arr3.push_back(200);
    cout << "arr3原始: ";
    for (int i = 0; i < arr3.showsize(); i++) cout << arr3[i] << " ";
    cout << endl;

    arr3 = arr1;  // 赋值操作
    cout << "arr3 = arr1 后: ";
    for (int i = 0; i < arr3.showsize(); i++) cout << arr3[i] << " ";
    cout << "，容量: " << arr3.showcapacity() << endl;

    cout << "========== test01 结束 ==========\n" << endl;
}


// test02：不同类型和边界测试
void test02() {
    cout << "========== test02：边界测试(string) ==========" << endl;

    // 1. string类型测试
    myarray<string> arr1(4);
    arr1.push_back("Hello");
    arr1.push_back("C++");
    arr1.push_back("Template");

    cout << "string数组: ";
    for (int i = 0; i < arr1.showsize(); i++) {
        cout << arr1[i] << " ";
    }
    cout << "，容量: " << arr1.showcapacity() << ", 大小: " << arr1.showsize() << endl;

    // 2. 容量满时插入测试
    cout << "\n容量满时插入测试(容量4，已插3个):" << endl;
    arr1.push_back("第四元素");
    cout << "插第四元素后大小: " << arr1.showsize() << endl;
    arr1.push_back("第五元素");  // 容量已满，插入失败
    cout << "插第五元素后大小: " << arr1.showsize() << " (应该不变)" << endl;

    // 3. 多次尾删测试
    cout << "\n多次尾删测试:" << endl;
    cout << "当前数组: ";
    for (int i = 0; i < arr1.showsize(); i++) cout << arr1[i] << " ";
    cout << endl;

    while (arr1.showsize() > 0) {
        cout << "删除: " << arr1[arr1.showsize() - 1];
        arr1.pop_back();
        cout << "，剩余大小: " << arr1.showsize() << endl;
    }

    // 4. 空数组删除测试（边界情况）
    cout << "\n空数组删除测试: ";
    arr1.pop_back();  // size=0，应该直接返回
    cout << "pop_back无影响，大小仍为: " << arr1.showsize() << endl;

    // 5. 构造后直接使用下标（未初始化区域访问风险）
    cout << "\n--- 下标访问注意事项 ---" << endl;
    myarray<int> arr2(5);
    arr2.push_back(10);
    arr2.push_back(20);
    cout << "arr2有效元素: ";
    for (int i = 0; i < arr2.showsize(); i++) cout << arr2[i] << " ";
    cout << endl;

    cout << "arr2容量内但未初始化的区域: ";
    // 注意：这是未初始化的内存，不应该读取！仅演示
    cout << arr2[2] << " (随机值)" << endl;  // 未初始化，行为未定义

    // 6. 常量对象测试（需要const成员函数，目前没有，演示编译错误）
    // const myarray<int> arr3(3);
    // arr3.showcapacity();  // 如果showcapacity不是const，这里会编译错误

    cout << "========== test02 结束 ==========\n" << endl;
}