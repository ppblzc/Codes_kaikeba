/*
 * @Descripttion: map简单应用
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-08 15:00:04
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 15:16:22
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    int n;//字典中一共有多少个单词
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;
        m[s] = t;
    }
    cin >> n;//要查询的单词个数
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }

}