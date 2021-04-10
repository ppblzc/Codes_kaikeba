/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-06 21:03:36
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 16:10:34
 */

#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
using namespace std;

int k, d, m, f;//守门员、后卫、中场、前锋的个数
int ktmp, dtmp, mtmp, ftmp;//每输入一个数，就push进优先队列，不需要动态数组去临时存储
//vector<int> kvec, dvec, mvec, fvec;//动态数组，存储各角色队员的得分
//priority_queue<int> kq, dq, mq, fq;//优先队列，由大到小存储各角色队员的得分
int q;//阵型个数

double ans;//平均分

double func(priority_queue<int> *que, int cnt) {
    int tmp = 0;
    for (int i = 0; i < cnt; i++) {
        tmp += que->top();
        que->pop();
    }
    return tmp;
}

int main() {
    cin >> k >> d >> m >> f;
    priority_queue<int> kq, dq, mq, fq;
    for (int i = 0; i < k; i++){
        cin >> ktmp;
        kq.push(ktmp);

    }

    for (int i = 0; i < d; i++){
        cin >> dtmp;
        dq.push(dtmp);   
    }
    
    for (int i = 0; i < m; i++){
        cin >> mtmp;
        mq.push(mtmp);
    }
    for (int i = 0; i < f; i++){
        cin >> ftmp;
        fq.push(ftmp);
    }
    

    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int X[10] = {0};//存储阵型类型
        cin >> X[0] >> X[1] >> X[2];
        ans = (func(&kq, 1) + func(&dq, X[0]) + func(&mq, X[1]) + func(&fq, X[2])) * 1.0 / 11.0;
        printf("%.2f\n", ans);
    }

    return 0;
}