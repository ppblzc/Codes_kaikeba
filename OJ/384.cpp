/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-07 17:16:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 09:08:16
 */
#include<iostream>
#include<queue>
using namespace std;

int func(int x) {
    if (x % 7 == 0) return 1;
    while(x) {
        if (x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}
int main(){
    int n, x, t;
    cin >> n >> x >> t;
    queue<int> que;
    for (int i = x; i <= n; i++) {
        que.push(i);
    }
    for (int i = 1; i < x; i++) {//i从1开始，不是0
        que.push(i);
    }
    while (que.size() != 1) {
        if (func(t)) que.pop();
        else {
            que.push(que.front());
            que.pop();
        }
        t++;
    }
    cout << que.front() << endl;
    return 0;
}