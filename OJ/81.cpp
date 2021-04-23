/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-19 15:00:05
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-19 17:36:53
 */
#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy, mark[2005][2005];
/*
mark[x][y] == 0 有、无手机状态下都未经过
mark[x][y] == 1 只在无手机的状态下经过
mark[x][y] == 2 只在有手机的状态下经过
mark[x][y] == 3 有、无手机状态下都经过
*/
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[2005][2005];
struct node
{
    int x, y, step, flag;//flag == 0未拥有手机，flag == 1已拥有
};


int main() {
    //scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //scanf("%c", &mmap[i][j]);
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    
    queue<node> que;
    que.push((node){sx, sy, 0, 0});
    mark[sx][sy] = 1;//起点去重，标记为无手机时来过
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T' && temp.flag == 1) {
                //printf("%d\n", temp.step + 1);
                cout << temp.step + 1 << endl;
                return 0;
            }
            //(x,y) 已经来过，两种情况
            //   |------无手机的状态下来过---------|           |---------有手机的情况下来过-------------|
            if ((temp.flag == 0 && (mark[x][y] & 1) != 0) || (temp.flag == 1 && (mark[x][y] & 2) != 0)) {
                continue;
            }
            //正常可以走的点
            if (mmap[x][y] == 'S' || mmap[x][y] == 'T' || mmap[x][y] == '.') {
                mark[x][y] += temp.flag + 1;
                que.push((node){x, y, temp.step + 1, temp.flag});
            }
            if (mmap[x][y] == 'P') {
                mark[x][y] = 3;
                que.push((node){x, y, temp.step + 1, 1});
            }
        }
    }

    return 0;
}