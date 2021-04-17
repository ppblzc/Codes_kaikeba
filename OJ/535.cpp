/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-16 17:04:32
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 10:34:03
 */
#include<iostream>
using namespace std;
int n, m, ans = 1, sx, sy;//sx,sy为起始点坐标
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};//方向数组：右、下、左、上
char mmap[55][55];

void func(int x, int y){
    for (int i = 0; i < 4; i++) {//遍历四个方向的行进
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] == '.') {//'.'说明可以继续进行，递归的终止条件
            ans++;
            mmap[xx][yy] = 0;//标记已经过的点
            func(xx, yy);//递归
        }
    }
}
int main() {
    cin >> m >> n;//注意读题，m、n的顺序
    for (int i = 1; i <= n; i++) { //行遍历，不是从0开始，是从1开始，避免访问越界
        for (int j = 1; j <= m; j++) { //列遍历
            cin >> mmap[i][j];
            if (mmap[i][j] == '@') {//起始位置
                sx = i, sy = j;
            }
        }
    }
    func(sx, sy);//深度搜索，使用递归实现
    cout << ans << endl;
    return 0;
}