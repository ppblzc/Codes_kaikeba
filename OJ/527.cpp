/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-19 10:44:58
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-19 14:06:17
 */
#include<iostream>
#include<queue>
using namespace std;

struct node{
    int x, y, step, d;
};
int n, m, d, mark[105][105][105];
char mmap[105][105];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int main() {
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    
    queue<node> que;
    que.push((node){1, 1, 0, d});//将起点放入搜索队列中
    //将起点标记去重
    for (int i = 0; i <= d; i++) {
        mark[1][1][i] = 1;
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            //先尝试飞行操作
            for (int j = 2; j <= temp.d; j++) {
                int x = temp.x + dir[i][0] * j;
                int y = temp.y + dir[i][1] * j;
                if (mmap[x][y] == 0) { //边界判断
                    break;
                }
                if (x == n && y == m) {
                    cout << temp.step + 1 << endl;
                    return 0;
                }
                if (mmap[x][y] == 'P' && mark[x][y][temp.d - j] == 0) {
                    mark[x][y][temp.d - j] == 1;
                    que.push((node){x, y, temp.step + 1, temp.d - j});
                }
            }
            //步行
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x == n && y == m) {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == 'P' && mark[x][y][temp.d] == 0) {
                mark[x][y][temp.d] = 1;
                que.push((node){x, y, temp.step + 1, temp.d});
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}