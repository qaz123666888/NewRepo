#include <iostream>
#include <string>
using namespace std;

// 函数模板：对任意类型的数组进行排序（选择排序）
template<typename T>
void mySort(T arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;  // 假设当前位置是最小值
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[minIndex]) {  // 找更小的
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // 交换
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// 打印数组的函数模板
template<typename T>
void printArray(const T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}   

// 测试案例
void test01() {
    cout << "====== double类型数组排序 ======" << endl;
    double dArr[] = { 3.14, 2.71, 1.618, 0.618, 2.0 };
    int dLen = sizeof(dArr) / sizeof(dArr[0]);

    cout << "排序前：";
    printArray(dArr, dLen);

    mySort(dArr, dLen);

    cout << "排序后：";
    printArray(dArr, dLen);

    cout << endl;

    cout << "====== string类型数组排序 ======" << endl;
    string sArr[] = { "banana", "apple", "orange", "grape", "pear" };
    int sLen = sizeof(sArr) / sizeof(sArr[0]);

    cout << "排序前：";
    printArray(sArr, sLen);

    mySort(sArr, sLen);

    cout << "排序后：";
    printArray(sArr, sLen);
}

int main() {
    test01();
    return 0;
}