/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-03-27 14:38:28
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-05 12:19:42
 */
#include<iostream>
using namespace std;

int n;
int num[15];

void print(int cnt) {
    for (int i = 1; i <= cnt; i++ ){
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func(int s, int deep) {
    for (int i = s; i <= n; i++) {
        num[deep] = i;
        print(deep);//选到了第几个数
        func(i + 1, deep + 1);
    }
}

int main() {
    cin >> n;
    func(1, 1);
    return 0;
}