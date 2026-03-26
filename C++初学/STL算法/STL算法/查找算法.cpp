#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = { 15, 22, 9, 44, 22, 7, 9, 33 };

    // 1. find - 查找值 22
    auto it1 = std::find(v.begin(), v.end(), 22);
    std::cout << "第一个22在索引: " << std::distance(v.begin(), it1) << std::endl;

    // 2. find_if - 查找第一个大于 20 的数
    auto it2 = std::find_if(v.begin(), v.end(), [](int n) { return n > 20; });
    std::cout << "第一个大于20的数: " << *it2 << std::endl;

    // 3. adjacent_find - 查找相邻重复
    auto it3 = std::adjacent_find(v.begin(), v.end());
    if (it3 == v.end()) std::cout << "无相邻重复元素" << std::endl;

    // 4. 排序后使用二分查找
    std::sort(v.begin(), v.end());  // {7, 9, 9, 15, 22, 22, 33, 44}
    bool exists = std::binary_search(v.begin(), v.end(), 22);
    std::cout << "22是否存在: " << std::boolalpha << exists << std::endl;

    // 5. equal_range - 统计 22 出现次数
    auto range = std::equal_range(v.begin(), v.end(), 22);
    std::cout << "22出现次数: " << (range.second - range.first) << std::endl;

    return 0;
}