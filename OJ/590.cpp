/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-10 17:22:00
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-10 18:14:08
 */
#include<iostream>
#include<cstdio>
using namespace std;

int n, m, num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005], mmax_ind[1005], mmax2[1005];
int main() {
    scanf("%d%d", &n, &m);
    //输入原数组
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    //从上往下求
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    //从下往上求
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }
    //
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
        }
    }
    //开始求解
    for (int i = 2; i <= n; i++) {
        int t = 0, t2 = 0, ind = 0;//t最大值，t2次大值，ind最大值下标
        for (int j = 1; j <= i; j++) {
            if (t < ans[i][j]) {
                t2 = t;
                t = ans[i][j];
                ind = j;
            } else if (t2 < ans[i][j]) {
                t2 = ans[i][j];
            }
        }
        mmax[i] = t, mmax_ind[i] = ind, mmax2[i] = t2;
    }
    
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x == 1) printf("-1\n");
        else if (y == mmax_ind[x]) {
            printf("%d\n", mmax2[x]);
        } else {
            printf("%d\n", mmax[x]);
        }
    }
    return 0;
}