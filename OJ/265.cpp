//栈最一开始是空的，没有已匹配的位置，设置守护位（在栈底存入）
#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> s1; //存括号
stack<int> s2; //存上一个匹配的下标
string s; //括号序列
int ans; 

void cle(int x) {
    while (!s1.empty()) {
        s2.pop();
        s1.pop();
    }
    s1.push('#');//清空后重新设置标志位
    s2.push(x);
}

int main() {
    cin >> s;
    s1.push('#'); //设置的守护位，就不需要判断栈为空的情况
    s2.push(-1); //设置的守护位,栈顶存储上一个不匹配位置的下标
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            s1.push(s[i]);
            s2.push(i);
        } else if (s[i] == ')') {
            if (s1.top() == '(') {
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            } else {
                cle(i);
            }
        } else if (s[i] == ']') {
            if (s1.top() == '[') {
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            } else {
                cle(i);
            }
        } else if (s[i] == '}') {
            if (s1.top() == '{') {
                s1.pop();
                s2.pop();
                ans = max(ans, i - s2.top());
            } else {
                cle(i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}