/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-10 14:56:02
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-10 15:35:19
 */
#include<iostream>
#include<cstdio>
using namespace std;

int num[1005][1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &num[i][j]);
            //num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);//从上往下
        }
    }

for (int i = n; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
        num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);//从下往上
    }
}
printf("%d\n", num[1][1]);   
    /*
    int ans = 0;
    for (int i = i; i <= n; i++) {
        ans = max(ans, num[n][i]);
    }
    printf("%d\n", ans);
    */
    return 0;
}