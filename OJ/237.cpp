/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-05 16:33:14
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-05 17:56:41
 */

#include<iostream>
using namespace std;

int n;
int num[15], mark[15];//mark[]用来标记，防止重复输出
int cnt = 1; //当前递归所在的层数，体现回溯

void output() {
    for (int i = 1; i <= n; i++) {//每行都要输出n个数
        if (i != 1) {
            cout << " ";
        }
        cout << num[i];
    }
    cout << endl;
}

void func() {
    //递归边界
    if (cnt == n + 1) {
        output();
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0) {
            num[cnt] = i;
            mark[i] = 1;
            cnt++;
            func();
            cnt--;//回溯
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    func();
    return 0;
}