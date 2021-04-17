/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-12 21:54:39
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-15 22:22:08
 */


#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> sta;
string s;

int main() {
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
            while (!sta.empty()) {
                cout << sta.top();
                sta.pop();
            }
            cout << "." << endl;
            return 0;
        } else if (s[i] == ' ') {
            while (!sta.empty()) {
                cout << sta.top();
                sta.pop();
            }
            cout << " ";
        } else {
            sta.push(s[i]);
        }
        }
        
    }


    return 0;
}