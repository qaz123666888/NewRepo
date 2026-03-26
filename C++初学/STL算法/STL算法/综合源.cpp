#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <random>
#include <string>

// ==================== 泛型类和函数模板 ====================
// 通用打印模板
template<typename Container>
void print(const Container& c, const std::string& name) {
    std::cout << name << ": ";
    for (const auto& elem : c) std::cout << elem << " ";
    std::cout << std::endl;
}

// 函数对象类（仿函数）
class MultiplyBy {
private:
    int factor_;
public:
    MultiplyBy(int factor) : factor_(factor) {}
    int operator()(int x) const { return x * factor_; }
};

// 二元谓词类
class CompareByLastDigit {
public:
    bool operator()(int a, int b) const {
        return (a % 10) < (b % 10);
    }
};

// 学生类，用于演示稳定排序和查找
class Student {
private:
    std::string name_;
    int score_;
public:
    Student(std::string name, int score) : name_(name), score_(score) {}
    std::string getName() const { return name_; }
    int getScore() const { return score_; }
    bool operator==(const Student& other) const { return score_ == other.score_; }
    friend std::ostream& operator<<(std::ostream& os, const Student& s) {
        os << s.name_ << "(" << s.score_ << ")";
        return os;
    }
};

// 一元谓词函数
bool isEven(int n) { return n % 2 == 0; }
bool isOdd(int n) { return n % 2 != 0; }

// ==================== 1. 遍历算法 ====================
void demo_traversal() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    // for_each: 使用 Lambda 打印
    std::cout << "for_each: ";
    std::for_each(v.begin(), v.end(), [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    // for_each: 使用函数对象修改元素
    std::for_each(v.begin(), v.end(), [](int& n) { n *= 2; });
    print(v, "for_each 加倍后");

    // transform: 一元变换，生成新序列
    std::vector<int> squares(v.size());
    std::transform(v.begin(), v.end(), squares.begin(),
        [](int n) { return n * n; });
    print(squares, "transform 平方");

    // transform: 二元变换（对应元素相加）
    std::vector<int> a = { 1, 2, 3 }, b = { 10, 20, 30 }, c(3);
    std::transform(a.begin(), a.end(), b.begin(), c.begin(),
        std::plus<int>());
    print(c, "transform 二元加法");
}

// ==================== 2. 查找算法 ====================
void demo_search() {
    std::vector<int> v = { 10, 20, 30, 20, 40, 50, 20, 60 };

    // find: 查找特定值
    auto it = std::find(v.begin(), v.end(), 20);
    if (it != v.end())
        std::cout << "find 找到 20 在位置: " << std::distance(v.begin(), it) << std::endl;

    // find_if: 查找第一个满足条件的元素
    it = std::find_if(v.begin(), v.end(), [](int n) { return n > 45; });
    if (it != v.end())
        std::cout << "find_if 第一个 >45 的元素: " << *it << std::endl;

    // find_if_not: 查找第一个不满足条件的元素
    it = std::find_if_not(v.begin(), v.end(), [](int n) { return n < 50; });
    if (it != v.end())
        std::cout << "find_if_not 第一个 >=50 的元素: " << *it << std::endl;

    // adjacent_find: 查找相邻重复
    std::vector<int> dup = { 1, 2, 2, 3, 4, 4, 5 };
    it = std::adjacent_find(dup.begin(), dup.end());
    if (it != dup.end())
        std::cout << "adjacent_find 相邻重复: " << *it << std::endl;

    // binary_search: 二分查找（需有序）
    std::sort(v.begin(), v.end());
    bool found = std::binary_search(v.begin(), v.end(), 30);
    std::cout << "binary_search 30 是否存在: " << std::boolalpha << found << std::endl;

    // lower_bound / upper_bound / equal_range
    std::vector<int> multi = { 10, 20, 20, 20, 30, 40 };
    auto lb = std::lower_bound(multi.begin(), multi.end(), 20);
    auto ub = std::upper_bound(multi.begin(), multi.end(), 20);
    std::cout << "lower_bound 第一个20位置: " << std::distance(multi.begin(), lb) << std::endl;
    std::cout << "upper_bound 最后一个20之后位置: " << std::distance(multi.begin(), ub) << std::endl;

    auto range = std::equal_range(multi.begin(), multi.end(), 20);
    std::cout << "equal_range 20 出现 " << (range.second - range.first) << " 次" << std::endl;

    // search: 查找子区间
    std::vector<int> pattern = { 20, 30 };
    it = std::search(v.begin(), v.end(), pattern.begin(), pattern.end());
    if (it != v.end())
        std::cout << "search 找到子区间 {20,30} 位置: " << std::distance(v.begin(), it) << std::endl;

    // find_first_of: 查找任一目标元素
    std::vector<int> targets = { 50, 30, 70 };
    it = std::find_first_of(v.begin(), v.end(), targets.begin(), targets.end());
    if (it != v.end())
        std::cout << "find_first_of 找到目标元素: " << *it << std::endl;

    // 在自定义类中使用 find
    std::vector<Student> students = { {"Alice", 85}, {"Bob", 92}, {"Charlie", 78} };
    auto sit = std::find_if(students.begin(), students.end(),
        [](const Student& s) { return s.getScore() > 90; });
    if (sit != students.end())
        std::cout << "find_if 找到高分学生: " << *sit << std::endl;
}

// ==================== 3. 排序算法 ====================
void demo_sorting() {
    std::vector<int> v = { 5, 2, 8, 1, 9, 3, 7, 4, 6, 2, 5 };

    // sort: 默认升序
    std::sort(v.begin(), v.end());
    print(v, "sort 升序");

    // sort: 降序（使用函数对象）
    std::sort(v.begin(), v.end(), std::greater<int>());
    print(v, "sort 降序");

    // stable_sort: 稳定排序（演示使用自定义类）
    std::vector<Student> students = { {"Alice", 85}, {"Bob", 85}, {"Charlie", 90}, {"David", 85} };
    std::stable_sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) { return a.getScore() < b.getScore(); });
    std::cout << "stable_sort 稳定排序: ";
    for (const auto& s : students) std::cout << s << " ";
    std::cout << std::endl;

    // partial_sort: 部分排序（前5个最小）
    std::vector<int> v2 = { 9, 1, 8, 2, 7, 3, 6, 4, 5 };
    std::partial_sort(v2.begin(), v2.begin() + 5, v2.end());
    print(v2, "partial_sort 前5个最小");

    // nth_element: 找第N小元素
    std::vector<int> v3 = { 5, 2, 8, 1, 9, 3, 7, 4, 6 };
    std::nth_element(v3.begin(), v3.begin() + 4, v3.end());
    std::cout << "nth_element 第5小元素: " << v3[4] << std::endl;

    // reverse: 反转
    std::vector<int> rev = { 1, 2, 3, 4, 5 };
    std::reverse(rev.begin(), rev.end());
    print(rev, "reverse 反转");

    // shuffle: 随机打乱
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<int> shuffle_vec = { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::shuffle(shuffle_vec.begin(), shuffle_vec.end(), g);
    print(shuffle_vec, "shuffle 随机打乱");

    // merge: 合并两个有序区间
    std::vector<int> a = { 1, 3, 5, 7 };
    std::vector<int> b = { 2, 4, 6, 8 };
    std::vector<int> merged(8);
    std::merge(a.begin(), a.end(), b.begin(), b.end(), merged.begin());
    print(merged, "merge 合并有序区间");
}

// ==================== 4. 拷贝和替换算法 ====================
void demo_copy_replace() {
    std::vector<int> src = { 1, 2, 3, 4, 5, 2, 6, 2, 7 };

    // copy: 基本拷贝
    std::vector<int> dest1(src.size());
    std::copy(src.begin(), src.end(), dest1.begin());
    print(dest1, "copy 基本拷贝");

    // copy_if: 条件拷贝（拷贝所有偶数）
    std::vector<int> dest2;
    std::copy_if(src.begin(), src.end(), std::back_inserter(dest2),
        [](int n) { return n % 2 == 0; });
    print(dest2, "copy_if 拷贝偶数");

    // copy_n: 拷贝前N个
    std::vector<int> dest3(3);
    std::copy_n(src.begin(), 3, dest3.begin());
    print(dest3, "copy_n 拷贝前3个");

    // copy_backward: 逆向拷贝
    std::vector<int> backward_vec = { 1, 2, 3, 4, 5 };
    std::copy_backward(backward_vec.begin(), backward_vec.begin() + 3, backward_vec.begin() + 5);
    print(backward_vec, "copy_backward 逆向拷贝");

    // replace: 替换指定值
    std::vector<int> rep1 = src;
    std::replace(rep1.begin(), rep1.end(), 2, 99);
    print(rep1, "replace 将2替换为99");

    // replace_if: 条件替换
    std::vector<int> rep2 = src;
    std::replace_if(rep2.begin(), rep2.end(),
        [](int n) { return n % 2 == 0; }, 0);
    print(rep2, "replace_if 将偶数替换为0");

    // replace_copy: 替换并拷贝
    std::vector<int> rep3(src.size());
    std::replace_copy(src.begin(), src.end(), rep3.begin(), 2, 999);
    print(rep3, "replace_copy 替换2为999并拷贝");

    // swap: 交换两个容器
    std::vector<int> a = { 1, 2, 3 };
    std::vector<int> b = { 9, 8, 7 };
    std::swap(a, b);
    print(a, "swap 交换后a");
    print(b, "swap 交换后b");

    // iter_swap: 交换迭代器指向的元素
    std::vector<int> v = { 10, 20, 30, 40 };
    std::iter_swap(v.begin(), v.begin() + 2);
    print(v, "iter_swap 交换首尾");
}

// ==================== 5. 算术生成算法 ====================
void demo_arithmetic() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    // accumulate: 累加
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "accumulate 累加: " << sum << std::endl;

    // accumulate: 累乘
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    std::cout << "accumulate 累乘: " << product << std::endl;

    // iota: 生成递增序列
    std::vector<int> seq(10);
    std::iota(seq.begin(), seq.end(), 100);
    print(seq, "iota 生成递增序列");

    // fill: 填充固定值
    std::vector<int> filled(8);
    std::fill(filled.begin(), filled.end(), 42);
    print(filled, "fill 填充42");

    // partial_sum: 前缀和
    std::vector<int> prefix(v.size());
    std::partial_sum(v.begin(), v.end(), prefix.begin());
    print(prefix, "partial_sum 前缀和");

    // adjacent_difference: 相邻差
    std::vector<int> diff(v.size());
    std::adjacent_difference(prefix.begin(), prefix.end(), diff.begin());
    print(diff, "adjacent_difference 相邻差");

    // inner_product: 点积
    int dot = std::inner_product(v.begin(), v.end(), v.begin(), 0);
    std::cout << "inner_product 自身点积: " << dot << std::endl;
}

// ==================== 6. 集合算法 ====================
void demo_set() {
    std::vector<int> A = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> B = { 4, 5, 6, 7, 8, 9 };
    std::vector<int> result;

    // set_intersection: 交集
    std::set_intersection(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(result));
    print(result, "set_intersection A∩B");

    // set_union: 并集
    result.clear();
    std::set_union(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(result));
    print(result, "set_union A∪B");

    // set_difference: 差集 A - B
    result.clear();
    std::set_difference(A.begin(), A.end(), B.begin(), B.end(),
        std::back_inserter(result));
    print(result, "set_difference A-B");

    // set_symmetric_difference: 对称差集
    result.clear();
    std::set_symmetric_difference(A.begin(), A.end(),
        B.begin(), B.end(),
        std::back_inserter(result));
    print(result, "set_symmetric_difference A⊕B");

    // includes: 判断子集
    std::vector<int> sub = { 2, 4, 6 };
    bool is_sub = std::includes(A.begin(), A.end(),
        sub.begin(), sub.end());
    std::cout << "includes {2,4,6} 是子集: " << std::boolalpha << is_sub << std::endl;
}

// ==================== 主函数 ====================
int main() {
    std::cout << "========== 1. 遍历算法 ==========" << std::endl;
    demo_traversal();

    std::cout << "\n========== 2. 查找算法 ==========" << std::endl;
    demo_search();

    std::cout << "\n========== 3. 排序算法 ==========" << std::endl;
    demo_sorting();

    std::cout << "\n========== 4. 拷贝和替换算法 ==========" << std::endl;
    demo_copy_replace();

    std::cout << "\n========== 5. 算术生成算法 ==========" << std::endl;
    demo_arithmetic();

    std::cout << "\n========== 6. 集合算法 ==========" << std::endl;
    demo_set();

    return 0;
}