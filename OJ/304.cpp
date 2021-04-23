/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-18 11:48:47
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-18 12:16:25
 */

#include<iostream>
#include<queue>
using namespace std;

int n, m, sx, sy;//n行m列
char mmap[155][155];
int dir[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

struct node{
    int x, y, step;
};

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                sx = i, sy =j;
            }
        }
    }
    //建立搜索队列
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[xx][yy] == '.') {
                mmap[xx][yy] = 0;
                que.push((node){xx, yy, temp.step + 1});
            }
        }
    }
    

    return 0;
}