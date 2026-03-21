#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    double score;

public:
    Student() : id(0), score(0) {}
    Student(string n, int i, double s) : name(n), id(i), score(s) {}

    // 显示学生信息
    void display() const {
        cout << "学号: " << id << ", 姓名: " << name << ", 成绩: " << score << endl;
    }

    // 获取数据用于保存
    string toString() const {
        return name + "," + to_string(id) + "," + to_string(score);
    }

    // 从字符串解析（从字符串中获取学生信息)
    static Student fromString(const string& line) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);

        string name = line.substr(0, pos1);
        int id = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        double score = stod(line.substr(pos2 + 1));

        return Student(name, id, score);
    }
};

class StudentManager {
private:
    vector<Student> students;
    string filename;

public:
    StudentManager(const string& file) : filename(file) {
        loadFromFile();  // 构造函数中自动加载
    }

    // 添加学生
    void addStudent(const Student& s) {
        students.push_back(s);
        saveToFile();
    }

    // 显示所有学生
    void displayAll() {
        if (students.empty()) {
            cout << "暂无学生数据" << endl;
            return;
        }

        for (const auto& s : students) {
            s.display();
        }
    }

    // 保存到文件
    void saveToFile() {
        ofstream outFile(filename);
        if (!outFile) {
            cerr << "保存失败！" << endl;
            return;
        }

        for (const auto& s : students) {
            outFile << s.toString() << endl;
        }

        outFile.close();
        cout << "保存成功！" << endl;
    }

    // 从文件加载
    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "文件不存在，将创建新文件" << endl;
            return;
        }

        students.clear();
        string line;
        while (getline(inFile, line)) {
            if (!line.empty()) {
                students.push_back(Student::fromString(line));
            }
        }

        inFile.close();
        cout << "加载了 " << students.size() << " 条记录" << endl;
    }
};

int main() {
    StudentManager sm("students.txt");

    int choice;
    do {
        cout << "\n=== 学生成绩管理系统 ===" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 显示所有学生" << endl;
        cout << "3. 退出" << endl;
        cout << "请选择: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            int id;
            double score;

            cout << "请输入姓名: ";
            cin >> name;
            cout << "请输入学号: ";
            cin >> id;
            cout << "请输入成绩: ";
            cin >> score;

            sm.addStudent(Student(name, id, score));
            break;
        }
        case 2:
            sm.displayAll();
            break;
        case 3:
            cout << "再见！" << endl;
            break;
        default:
            cout << "无效选择！" << endl;
        }
    } while (choice != 3);

    return 0;
}



//ifstream ifs       ifs.open (打开方式)（是否成功）   buf【1024】={0}（读文件中的数据）-》1.while（ifs》》buf【】） 2.while（ifs.getline(buf，sizeof（buf）)）3.string buf类似2 4.（不推荐）（while（c=ifs。get（）！=eof（文件尾巴）））
// 
//  ifs.close
//