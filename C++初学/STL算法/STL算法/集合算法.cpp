#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

template<typename T>
void print(const std::vector<T>& v, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& elem : v) std::cout << elem << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> A = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> B = { 4, 5, 6, 7, 8, 9 };
    std::vector<int> C;

    // 1. 交集
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(C));
    print(C, "A ∩ B");  // 4 5 6

    // 2. 并集
    C.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(C));
    print(C, "A ∪ B");  // 1 2 3 4 5 6 7 8 9

    // 3. 差集 A - B
    C.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(C));
    print(C, "A - B");  // 1 2 3

    // 4. 差集 B - A
    C.clear();
    std::set_difference(B.begin(), B.end(), A.begin(), A.end(),
        std::back_inserter(C));
    print(C, "B - A");  // 7 8 9

    // 5. 对称差集
    C.clear();
    std::set_symmetric_difference(A.begin(), A.end(),
        B.begin(), B.end(),
        std::back_inserter(C));
    print(C, "A ⊕ B");  // 1 2 3 7 8 9

    // 6. 判断子集
    std::vector<int> sub = { 2, 4, 6 };
    bool is_sub = std::includes(A.begin(), A.end(),
        sub.begin(), sub.end());
    std::cout << std::boolalpha << "{2,4,6} 是 {1,2,3,4,5,6} 的子集: "
        << is_sub << std::endl;  // true

    return 0;
}