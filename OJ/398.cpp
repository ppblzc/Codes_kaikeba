/*
 * @Descripttion: 398 马的遍历
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 23:31:29
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 23:50:48
 */

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, sx, sy;
int ans[405][405];
int dir[8][2] = {{1,2},{2,1},{1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2,-1}};

int main() {
    cin >> n >> m >> sx >> sy;
    ans[sx][sy] = -1;
    queue<node> que;
    que.push((node){sx, sy, 0});//搜索队列
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            //  |-------------边界--------------|    |----去重----|
            if (x < 1 || y < 1 || x > n || y > m || ans[x][y] != 0) {
                continue;
            }
            ans[x][y] = temp.step + 1;
            que.push((node){x, y, ans[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (ans[i][j] == -1) cout << 0;
            else if (ans[i][j] == 0) cout << -1;
            else cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}