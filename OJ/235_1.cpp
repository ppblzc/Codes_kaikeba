/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-05 14:37:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-05 14:50:53
 */

#include<iostream>
using namespace std;

int n;
int num[15];
int cnt = 1;//用来定位当前所在层

void output(){
    for (int i = 1; i <= cnt; i++) {
        if (i != 1) cout << " ";
        cout << num[i];
    }
    cout << endl;
}

void func(int start) {//start表示从数字几开始
    for (int i = start; i <= n; i++) {
        num[cnt] = i;
        output();
        cnt++;
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);//

    return 0;
}