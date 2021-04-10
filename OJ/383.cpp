/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-08 14:24:22
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 14:35:24
 */

#include<iostream>
#include<queue>
using namespace std;

int x, y, n;//男生、女生、n首曲子

int main() {
    cin >> x >> y >> n;
    queue<int> xque, yque;
    for (int i = 1; i <= x; i++) {
        xque.push(i);
    }
    for (int i = 1; i <= y; i++) {
        yque.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << xque.front() << " " << yque.front() << endl;
        xque.push(xque.front());
        yque.push(yque.front());
        xque.pop();
        yque.pop();
    }

    return 0;
}