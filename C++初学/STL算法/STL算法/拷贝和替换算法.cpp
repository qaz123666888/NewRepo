#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(const std::vector<int>& v, const std::string& name) {
    std::cout << name << ": ";
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> src = { 1, 2, 3, 4, 5, 2, 6, 2, 7 };
    std::vector<int> dest;

    // 1. copy_if - 拷贝所有大于 3 的元素
    std::copy_if(src.begin(), src.end(), std::back_inserter(dest),
        [](int n) { return n > 3; });
    print(dest, "大于3的元素");  // 4 5 6 7

    // 2. replace - 将 2 替换为 99
    std::vector<int> v1 = src;
    std::replace(v1.begin(), v1.end(), 2, 99);
    print(v1, "替换2为99");  // 1 99 3 4 5 99 6 99 7

    // 3. replace_if - 将偶数替换为 0
    std::vector<int> v2 = src;
    std::replace_if(v2.begin(), v2.end(),
        [](int n) { return n % 2 == 0; }, 0);
    print(v2, "偶数替换为0");  // 1 0 3 0 5 0 0 0 7

    // 4. replace_copy - 替换并拷贝
    std::vector<int> v3(src.size());
    std::replace_copy(src.begin(), src.end(), v3.begin(), 2, 999);
    print(v3, "替换2为999并拷贝");  // 1 999 3 4 5 999 6 999 7

    // 5. swap - 交换两个向量
    std::vector<int> a = { 1, 2, 3 };
    std::vector<int> b = { 9, 8, 7 };
    std::swap(a, b);
    print(a, "交换后a");  // 9 8 7
    print(b, "交换后b");  // 1 2 3

    return 0;
}