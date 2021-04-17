/*
 * @Descripttion: 地图搜索问题
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-16 10:00:16
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-16 10:32:22
 */
#include<iostream>
using namespace std;

int n, m, sx, sy, ex, ey;
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char mmap[105][105];

int func(int x, int y) { //从(x,y)点出发，能否走到目标
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == 'T') return 1;
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = 0;
            int t = func(xx, yy);//递归
            if (t) return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (mmap[i][j] == 'T') {
                ex = i, ey = j;
            }
        }
    }
    int t = func(sx, sy);
    t && cout << "yes! find it." << endl;
    !t && cout << "not find." << endl;
}