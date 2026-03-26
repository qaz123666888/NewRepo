#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

void print(const std::vector<int>& v, const std::string& name) {
    std::cout << name << ": ";
    for (int n : v) std::cout << n << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v(8);

    // 1. iota 生成 0~7
    std::iota(v.begin(), v.end(), 0);
    print(v, "原序列");  // 0 1 2 3 4 5 6 7

    // 2. accumulate 求和
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "总和: " << sum << std::endl;  // 28

    // 3. partial_sum 前缀和
    std::vector<int> prefix(v.size());
    std::partial_sum(v.begin(), v.end(), prefix.begin());
    print(prefix, "前缀和");  // 0 1 3 6 10 15 21 28

    // 4. adjacent_difference 相邻差（还原原序列）
    std::vector<int> diff(v.size());
    std::adjacent_difference(prefix.begin(), prefix.end(), diff.begin());
    print(diff, "相邻差");  // 0 1 2 3 4 5 6 7

    // 5. inner_product 计算点积（自身）
    int dot = std::inner_product(v.begin(), v.end(), v.begin(), 0);
    std::cout << "自身点积(平方和): " << dot << std::endl;  // 0+1+4+9+16+25+36+49=140

    // 6. fill 重置
    std::fill(v.begin(), v.end(), 100);
    print(v, "fill填充");  // 100 100 100 100 100 100 100 100

    return 0;
}