/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-19 20:30:38
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-19 21:03:29
 */
#include<iostream>
using namespace std;

int n, m, ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[2005][2005];
int mark[2005][2005];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || mark[xx][yy] == 1) {
            continue;
        }
        if (mmap[xx][yy] != mmap[x][y]) {
            mark[xx][yy] = 1;
            func(xx, yy);
        }
    }
    
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> &mmap[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mark[i][j] != 1) {
                func(i, j);
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}