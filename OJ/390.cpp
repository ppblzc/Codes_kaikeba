/*
 * @Descripttion: 二分答案
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-12 10:53:00
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-12 13:47:28
 */
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, rawr;//原木的根数，目标段数, 二分的上边界
int num[100005];//存储原木的长度

int func(int x) {//段长度为x时，计算可截取的总段数
    int t = 0;
    for (int i = 0; i < n; i++) {
        t += num[i] / x;
    }
    return t;
}

int bs() {
    int l = 1, r = rawr;//二分的左右边界，此题类型为11111111000000型
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int s = func(mid);//段长度为mid时，可切出的段数s,s是临时的变量
        if (s >= m) {
            l = mid;//s位于1区，mid可能是答案
        } else {
            r = mid - 1;//s位于0区，mid不是答案
        }
    }
    return r;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        scanf("%d", &num[i]);
        rawr = max(rawr, num[i]);//更新边界
    }
    printf("%d\n", bs());
    return 0;
}