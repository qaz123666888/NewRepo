#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

// 注意：二进制文件只能用固定大小的结构体
struct Student {
    char name[20];
    int id;
    double score;
};

class BinaryStudentManager {
private:
    vector<Student> students;
    string filename;

public:
    BinaryStudentManager(const string& file) : filename(file) {
        loadFromFile();
    }

    // 添加学生
    void addStudent(const char* name, int id, double score) {
        Student s;
        strcpy_s(s.name, name);
        s.id = id;
        s.score = score;
        students.push_back(s);
        saveToFile();
    }

    // 显示所有学生
    void displayAll() {
        if (students.empty()) {
            cout << "暂无数据" << endl;
            return;
        }

        for (const auto& s : students) {
            cout << "姓名: " << s.name
                << ", 学号: " << s.id
                << ", 成绩: " << s.score << endl;
        }
    }

    // 保存到二进制文件
    void saveToFile() {
        // 二进制写模式
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "保存失败！" << endl;
            return;
        }

        // 逐个写入每个学生结构体
        for (const auto& s : students) {
            outFile.write(reinterpret_cast<const char*>(&s), sizeof(Student));
        }

        outFile.close();
        cout << "二进制保存成功，共 " << students.size() << " 条记录" << endl;
    }

    // 从二进制文件加载
    void loadFromFile() {
        // 二进制读模式
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cout << "文件不存在，将创建新文件" << endl;
            return;
        }

        students.clear();
        Student s;

        // 循环读取每个结构体
        while (inFile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
            students.push_back(s);
        }

        inFile.close();
        cout << "二进制加载了 " << students.size() << " 条记录" << endl;
    }

    // 获取文件大小（演示ate用法）
    streampos getFileSize() {
        ifstream inFile(filename, ios::binary | ios::ate);  // ate使指针在末尾
        if (!inFile) return 0;
        streampos size = inFile.tellg();  // 得到文件大小
        inFile.close();
        return size;
    }
};

int main() {
    BinaryStudentManager bsm("students.dat");

    int choice;
    do {
        cout << "\n=== 二进制学生管理系统 ===" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 查看文件大小" << endl;
        cout << "4. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            char name[20];
            int id;
            double score;

            cout << "姓名: ";
            cin >> name;
            cout << "学号: ";
            cin >> id;
            cout << "成绩: ";
            cin >> score;

            bsm.addStudent(name, id, score);
            break;
        }
        case 2:
            bsm.displayAll();
            break;
        case 3:
            cout << "文件大小: " << bsm.getFileSize() << " 字节" << endl;
            cout << "每条记录大小: " << sizeof(Student) << " 字节" << endl;
            break;
        case 4:
            cout << "再见！" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}