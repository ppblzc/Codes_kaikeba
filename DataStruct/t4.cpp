/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-12 20:46:36
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-12 21:46:46
 */

#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int op, lim;

struct student {
    int num, cnt;
};

student stu[100005];
queue<int> que;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &op);
        int mmin = 0, mmax = 0;
        if (op == 1) {
            scanf("%d", &stu[i].cnt);
            stu[i].num = i;
            que.push(stu[i].cnt);
            mmax = max(mmax, stu[i].cnt);
            mmin = min(mmin, stu[i].cnt);
        } else if (op == 0) {
            if (que.empty()) {
                //printf("-1\n");
                continue;
            }
            //int t = que.front();
            //if 
            que.pop();
            //如何维护新的极值
            //mmax = max(mmax)
        } else if (op == 2) {
            scanf("%d",&lim);
            if (!que.empty()){
                if (lim == 0) printf("%d\n", mmin);
                else if (lim == 1) printf("%d\n", mmax);
            }
            else printf("-1\n");
        }
    }
    return 0;
}