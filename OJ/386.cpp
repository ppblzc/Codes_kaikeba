/*
 * @Descripttion: 排序 + 基础二分
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-11 17:44:01
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-11 18:24:27
 */
#include<algorithm>
#include<cstdio>
using namespace std;

struct node {
    int num, cnt;
};
node wm[100005];
int n, m;//n堆瓜，m次询问

bool cmp(const node &a, const node &b) {
    return a.cnt < b.cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {//输入各堆瓜的数据
        scanf("%d", &wm[i].cnt);
        wm[i].num = i + 1;
    }
    sort(wm, wm + n, cmp);//对瓜堆进行排序，为二分查找做准备
    for (int i = 0; i < m; i++) {
        int t;//每一组群众的目标数
        int l = 0, r = n - 1, flg = 0;//二分的左右指针,flg表示某轮循环中是否找到了目标值
        scanf("%d", &t);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (wm[mid].cnt == t) {//找到了
                flg = 1;
                printf("%d\n", wm[mid].num);
                break;
            } else if (wm[mid].cnt > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (flg == 0) {
            printf("0\n");
        }
    }

    return 0;
}