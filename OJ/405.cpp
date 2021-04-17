/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 17:19:13
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 17:43:53
 */

/*思路
(1)去重数组
(2)判断边界
(3)记忆化数组
0 1 1 --> mark 4 4 2
1 0 0 --> mark 4 4 2
(4)queue / stack
*/

#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

struct node
{
    int x, y;
};

int n, m, k, t, ans[3005][3005];//t用来临时存储相邻点的数量
stack<node> sta;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[3005][3005];
//搜索函数
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //  |--------------边界------------------|  |-----去重------|
        if (xx < 1 || yy < 1 || xx > n || yy > m || ans[xx][yy] != 0) { //判断是否越界
            continue;
        }
        if (mmap[x][y] != mmap[xx][yy]) {
            t++;
            ans[xx][yy] = 1; //mark,去重 
            sta.push((node){xx, yy});
            func(xx, yy);
            
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", &mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ans[i][j] == 0) {
                t = 1;
                ans[i][j] = 1;//此处充当标记数组作用
                sta.push((node){i, j});
                func(i, j);//求答案
                //递归结束，相邻点的坐标都在栈sta里，相邻点的个数都在t里
                while (!sta.empty()) { //实现存答案的过程
                    node temp = sta.top();
                    sta.pop();
                    ans[temp.x][temp.y] = t;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a][b]);
    }
    return 0;
}