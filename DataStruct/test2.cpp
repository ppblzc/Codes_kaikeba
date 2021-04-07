/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-06 20:20:04
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-06 20:32:52
 */


#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> s1; //存括号
string s; //括号序列

int main() {
    cin >> s;
    s1.push('#'); //设置的守护位，就不需要判断栈为空的情况
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            s1.push(s[i]);
        } else if (s[i] == ')') {
            if (s1.top() == '(') {
                s1.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == ']') {
            if (s1.top() == '[') {
                s1.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        } else if (s[i] == '}') {
            if (s1.top() == '{') {
                s1.pop();
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}