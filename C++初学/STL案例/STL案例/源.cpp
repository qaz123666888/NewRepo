#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>

using namespace std;

// 1. 定义部门枚举
enum class Department {
    Planning = 1,  // 策划部
    Art = 2,       // 美术部
    RAndD = 3      // 研发部
};

// 2. 员工类
class Employee {
public:
    string name;
    int salary;
    Department dept;

    Employee(string n, int s) : name(n), salary(s) {}

    void display() const {
        cout << "姓名: " << name << "\t工资: " << salary;
        switch (dept) {
        case Department::Planning:
            cout << "\t部门: 策划部";
            break;
        case Department::Art:
            cout << "\t部门: 美术部";
            break;
        case Department::RAndD:
            cout << "\t部门: 研发部";
            break;
        }
        cout << endl;
    }
};

// 3. 获取部门名称字符串
string getDeptName(Department dept) {
    switch (dept) {
    case Department::Planning: return "策划部";
    case Department::Art: return "美术部";
    case Department::RAndD: return "研发部";
    default: return "未知";
    }
}

int main() {
    // 设置随机种子
    srand(time(nullptr));

    // 1. 创建10名员工，放到vector中
    vector<Employee> employees;
    string names = "ABCDEFGHIJ";

    for (int i = 0; i < 10; i++) {
        string name = string(1, names[i]);  // 单个字符转字符串
        int salary = rand() % 10000 + 5000;  // 工资范围 5000-14999
        employees.emplace_back(name, salary);
    }

    // 2. 遍历vector，为每个员工随机分配部门
    for (auto& emp : employees) {
        int deptNum = rand() % 3 + 1;  // 随机 1-3
        emp.dept = static_cast<Department>(deptNum);
    }

    // 3. 将员工放入 multimap（部门编号作为key，员工对象作为value）
    multimap<int, Employee> deptMap;
    for (const auto& emp : employees) {
        int key = static_cast<int>(emp.dept);
        deptMap.insert({ key, emp });  // 或者 deptMap.insert(pair<int, Employee>(key, emp))
    }

    // 4. 分部门显示员工信息
    cout << "========== 员工分组信息 ==========" << endl;
    cout << endl;

    // 按部门编号顺序遍历
    for (int deptId = 1; deptId <= 3; deptId++) {
        Department dept = static_cast<Department>(deptId);
        cout << "【" << getDeptName(dept) << "】" << endl;
        cout << "----------------------------------------" << endl;

        // 获取该部门的员工范围
        auto range = deptMap.equal_range(deptId);
        int count = 0;

        for (auto it = range.first; it != range.second; ++it) {
            it->second.display();  // it->first 是 key，it->second 是 Employee
            count++;
        }

        if (count == 0) {
            cout << "暂无员工" << endl;
        }
        cout << endl;
    }

    // 额外：统计各部门人数和平均工资
    cout << "========== 部门统计 ==========" << endl;
    for (int deptId = 1; deptId <= 3; deptId++) {
        Department dept = static_cast<Department>(deptId);
        auto range = deptMap.equal_range(deptId);

        int count = 0;
        int totalSalary = 0;

        for (auto it = range.first; it != range.second; ++it) {
            count++;
            totalSalary += it->second.salary;
        }

        cout << getDeptName(dept) << ": "
            << count << "人, "
            << "平均工资: " << (count > 0 ? totalSalary / count : 0)
            << endl;
    }

    return 0;
}