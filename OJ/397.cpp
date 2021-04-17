/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 10:04:33
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 10:31:18
 */
#include<iostream>
using namespace std;

int n, m, ans;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int mmap[105][105];

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != 0) {
            mmap[xx][yy] = 0;
            func(xx, yy);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {//遍历输入，i,j从1开始，从0开始会访问越界！！！！！
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {//遍历判断目标区域
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] != 0) {
                ans++;
                mmap[i][j] = 0;//标记为0，避免重复判断
                func(i, j);//寻找坐标(i,j)点周围不为0的点
            }
        }
    }
    cout << ans << endl;
    return 0;
}