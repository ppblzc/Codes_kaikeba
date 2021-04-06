/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-05 15:28:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-05 15:42:12
 */
#include<iostream>
using namespace std;

int n, m;
int num[15];
int cnt = 1;

void output() {
    for(int i = 1; i <= m; i++) {
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int start, int left) {//本层从start开始选，还剩left个数要选
    if (left == 0) {
        output();
        return;
    }
    for (int i = start; i <= n; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);

    return 0;
}