/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-07 17:16:17
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-07 23:15:42
 */
#include<iostream>
#include<queue>
using namespace std;

queue<int> que;
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
    for (int i = x; i <= n; i++) {
        que.push(i);
    }
    for (int i = 0; i < x; i++) {
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