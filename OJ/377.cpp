#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
    stack<char> s;
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == ')') {
            if (!s.empty() && s.top() == '(') {
                s.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}