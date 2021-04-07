/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-06 21:03:36
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-07 09:38:42
 */

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int k, d, m, f;//守门员、后卫、中场、前锋的个数
vector<int> kvec, dvec, mvec, fvec;//动态数组，存储各角色队员的得分
priority_queue<int> kq, dq, mq, fq;//优先队列，由大到小存储各角色队员的得分
int q;//阵型个数
int X[10];//存储阵型类型
double ans;//平均分

int func(priority_queue<int> que, int cnt) {
    int tmp = 0;
    for (int i = 0; i < cnt; i++) {
        tmp += que.top();
        que.pop();
    }
    return tmp;
}

int main() {
    cin >> k >> d >> m >> f;
    char c;
    for (int i = 0; i < k; i++){
        while (cin >> kvec[i]) {
            if ((c = getchar()) == '\n') break;
            kq.push(kvec[i]);
        }
    }

    for (int i = 0; i < d; i++){
        while (cin >> dvec[i]) {
            if ((c = getchar()) == '\n') break;
            dq.push(dvec[i]); 
        }
    }
    for (int i = 0; i < m; i++){
        if ((c = getchar()) != '\n') {
            cin >> mvec[i];
            mq.push(mvec[i]);
        }
        else break;
    }
    for (int i = 0; i < f; i++){
        if ((c = getchar()) != '\n') {
            cin >> fvec[i];
            fq.push(fvec[i]);
        }
        else break;
    }
    

    cin >> q;
    
    for (int i = 0; i < q; i++) {
        cin >> X[0] >> X[1] >> X[2];
        func(kq, 1);
        func(dq, X[0]);
        func(mq, X[1]);
        func(fq, X[2]);
        ans = (func(kq, 1) + func(dq, X[0]) + func(mq, X[1]) + func(fq, X[2])) * 1.0 / 11;
        printf("%.2f\n", ans);
    }

    return 0;
}