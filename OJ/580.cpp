/*
 * @Descripttion: 使用set去重、排序
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-08 14:45:55
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 14:53:16
 */

#include<iostream>
#include<set>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }
    
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}