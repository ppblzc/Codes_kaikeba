/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-11 18:36:07
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-11 23:14:35
 */

#include<cstdio>
#include<algorithm>
using namespace std;

struct node{
    int num, cnt;
};

int n, m;
node wm[100005];
bool cmp(const node &a, const node &b) {
    return a.cnt < b.cnt;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wm[i].cnt);
        wm[i].num = i + 1;
    }
    wm[n].num = 0, wm[n].cnt = 2100000000;
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n;
        scanf("%d", &t);
        while (l != r) {
            int mid = (l + r) / 2;
            if (wm[mid].cnt >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", wm[l].num);
    }

    return 0;
}