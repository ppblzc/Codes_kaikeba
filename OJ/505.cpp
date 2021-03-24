/*************************************************************************
	> File Name: 505.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 06:26:42 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//排序规则，排序过后，从前往后连接的字典序 大于 从后往前连接的字典序
//前是什么，后又是什么？？？？
bool cmp (const string &a, const string &b) {
    return a + b > b + a;
}

int n;
string s[100005];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    } 
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}
