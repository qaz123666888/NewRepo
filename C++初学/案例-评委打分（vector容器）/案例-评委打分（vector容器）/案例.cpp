#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

class Player {
public:
    string name;
    double avgScore;

    Player(string n) : name(n), avgScore(0) {}
};

int main() {
    vector<Player> players;
    string names = "ABCDEFG";
    srand((unsigned int)time(nullptr));
    // 创建7名选手
    for (char c : names) {
        players.push_back("选手"+(string(1,c)));
    }

    // 每个选手打分
    for (auto& p : players) {
        deque<int> scores;
        int score;
        for (int i = 0; i < 5; i++) {
            score=rand()%41+60;
            scores.push_back(score);
        }

        sort(scores.begin(), scores.end());  
        int sum = 0;
        for (int s : scores) sum += s;
        p.avgScore = (double)sum / scores.size();
    }

    // 输出结果
    cout << "\n=== 最终成绩 ===" << endl;
    for (auto& p : players) {
        cout << p.name << " 平均分: " << p.avgScore << endl;
    }

    return 0;
}