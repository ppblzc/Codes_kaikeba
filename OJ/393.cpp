/*
 * @Descripttion: 二分答案 非整数问题 对保留特定小数位的处理
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-12 15:12:54
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-12 16:46:03
 */

#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int n, m;//n为总的绳子的根数，m为想要切成的段数
double num[10005];
double mmax;

int func(double x) {
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t;
}

double bs() {
    double l = 0, r = mmax;
    while (fabs(l - r) > 0.00005) {
        double mid = (l + r) / 2;
        int s = func(mid);
        if (s >= m) {
            l = mid;//不是整数，L和R更新时，都是mid
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);//记得更新mmax
    }
    double ans = bs();
    double t1 = (int)(ans * 100) / 100.0;//只保留两位小数，直接舍去两位以后的部分
    printf("%.2f\n", t1);
    return 0;
}