/*
 * @Descripttion: 399
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 18:32:32
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-18 11:24:34
 */

//广搜走地图
//队列
#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy;
char mmap[505][505];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

struct node {
    int x, y, step;
};

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '2') {
                sx = i, sy = j;
            }
        }
    }
    queue<node> que;//搜索队列
    que.push((node){sx, sy, 0});
    //以下while的结构实现了广搜
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == '3') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 0;//去重
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}