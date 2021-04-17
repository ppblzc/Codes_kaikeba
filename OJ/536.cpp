/*
 * @Descripttion: 地图搜索、字符串的输入/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 10:59:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 11:37:41
 */
#include<iostream>
using namespace std;
int n, m, ans, t;
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x,int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '1') {
            t++;
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '1') {
                t = 1;
                mmap[i][j] = 0;
                func(i, j);
                ans = max(ans, t);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
