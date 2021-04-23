/*
 * @Descripttion: 广搜
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-18 12:31:45
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-18 15:39:33
 */

#include<iostream>
#include<queue>
using namespace std;

int sx, sy;
int dir[12][2] = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}};

struct node{
    int x, y, step;
};

void func(int x, int y) {
    int mmap[505][505] = {0};
    mmap[x][y] = 1;//标记
    queue<node> que;
    que.push((node){x, y, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > 500 || yy > 500 || mmap[xx][yy] == 1) {
                continue;
            }
            if (xx == 1 && yy == 1) {
                //cout << temp.step + 1 << "(" << temp.x << "," << temp.y << ")" << endl;
                cout << temp.step + 1 << endl;
                while (!que.empty()) que.pop();//找到一个满足点，手动退出BFS过程
            } else {
                que.push((node){xx, yy, temp.step + 1});
                mmap[xx][yy] = 1;
            }
        } 
    }
    return;
}

int main() {
    for (int i = 0; i < 2; i++) {
        cin >> sx >> sy;
        func(sx, sy);
    }
    return 0;
}