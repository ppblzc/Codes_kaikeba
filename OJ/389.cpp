/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-12 14:28:41
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-12 15:09:06
 */
#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, num[100005];//n个位置、m个程序员待分配

int func(int x) {
    int t = 1, last = num[0];
    for (int i = 1; i < n; i++) {
        if (num[i] - last >= x) {
            t++;
            last = num[i];
        }
    }
    return t;
}

int bs() {
    int l = 1, r = num[n - 1] - num[0];
    while (l != r) {
        //此题二分答案类型为：111111100000000，找最后的1
        int mid = (l + r + 1) / 2;
        int s = func(mid);//当最小间隔为mid时，最多可容纳s个程序员,s是个临时值
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    printf("%d\n", bs());


    return 0;
}