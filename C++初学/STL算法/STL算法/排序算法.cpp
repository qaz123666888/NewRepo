#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

void print(const std::vector<int>& v) {
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };

    // 1. sort 升序
    std::sort(v.begin(), v.end());
    print(v);  // 1 2 3 4 5 6 7 8 9

    // 2. sort 降序
    std::sort(v.begin(), v.end(), std::greater<int>());
    print(v);  // 9 8 7 6 5 4 3 2 1

    // 3. nth_element - 找中位数
    std::nth_element(v.begin(), v.begin() + 4, v.end());
    std::cout << "中位数: " << v[4] << std::endl;  // 5

    // 4. partial_sort - 前3个最小
    std::vector<int> v2 = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    std::partial_sort(v2.begin(), v2.begin() + 3, v2.end());
    print(v2);  // 1 2 3 9 8 7 6 5 4

    // 5. merge 合并两个有序序列
    std::vector<int> a = { 1, 4, 7 };
    std::vector<int> b = { 2, 3, 8 };
    std::vector<int> c(6);
    std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    print(c);  // 1 2 3 4 7 8

    return 0;
}