#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool check(const string& str) {
    stack<char> s;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    string str;
    cout << "Enter brackets: ";
    cin >> str;

    if (check(str)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }

    return 0;
}