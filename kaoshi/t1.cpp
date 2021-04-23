/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-19 21:32:14
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-19 22:07:26
 */

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
    string str;
    int cnt;
};

int n;
node num[1005];
stack<char> sta;

void func(string s){
    for (int i = 0; i < s.size(); i++) {
        sta.push(s[i]);
    }
    while (!sta.empty()) {
        
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i].str;
        num[i].cnt = 
    }

    return 0;
}