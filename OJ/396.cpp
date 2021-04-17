/*
 * @Descripttion: 地图深搜、 边界判断、 判断连性
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-17 14:24:32
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-17 15:04:47
 */
#include<iostream>
using namespace std;

int n;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int mmap[35][35];
//判断联通性
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1) { //判断边界
            continue;
        }
        if (mmap[xx][yy] == 0) {//区别于被1包围的0
            mmap[xx][yy] = 3;
            func(xx, yy);
        }
    }
    
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    mmap[0][0] = 3;
    func(0, 0);//起点从0，0开始,对二维数组进行标记
    
    //遍历输出
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) {
                cout << " ";
            }
            if (mmap[i][j] == 0) {
                cout << 2;
            } else if (mmap[i][j] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;//遍历完一行，换行操作
    }
    return 0;
}