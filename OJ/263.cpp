/*
 * @Descripttion: 火车进栈
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-06 10:11:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-06 10:15:22
 */

#include<iostream>
#include<stack>
using namespace std;

int n;
stack<int> sta;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        sta.push(i);
    }
    return 0;
}