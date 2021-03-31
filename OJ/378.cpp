#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            if (!sta.empty() && sta.top() == '(') {
                sta.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == ']') {
            if (!sta.empty() && sta.top() == '[') {
                sta.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == '}') {
            if (!sta.empty() && sta.top() == '{') {
                sta.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    //全部遍历完之后，栈为空，说明括号匹配
    if (sta.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}