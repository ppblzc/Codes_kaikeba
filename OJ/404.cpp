/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 15:11:28
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-18 11:12:46
 */

#include<iostream>
using namespace std;

int n, m, sx, sy, t = 1;
char mmap[3005][3005];
int mark[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        //  |-------------边界------------------|   |-----去重------|
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] == 1) {
            continue;
        }
        if (mmap[xx][yy] != mmap[x][y]) {
            t++;
            mark[xx][yy] = 1;
            func(xx, yy);
        }
    }
}

int main () {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    cin >> sx >> sy;
    mark[sx][sy] = 1;
    func(sx, sy);
    cout << t << endl;
    return 0;
}