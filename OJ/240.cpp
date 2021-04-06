/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-04 16:25:45
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-04 17:01:21
 */

#include<iostream>
using namespace std;

char ans[1005][1005];//画出n=7的最大的图形
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729};//各尺寸的边长

void func(int x, int y, int n) {
    if (n == 1) { //递归的边界
        ans[x][y] = 'X';
        return;
    }
    func(x, y, n - 1);//左上角
    func(x, y + num[n] / 3 * 2, n - 1);//右上角
    func(x + num[n] / 3, y + num[n] / 3, n - 1);//中间
    func(x + num[n] / 3 * 2, y, n -1);//左下角
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n -1);//右下角
}

int main() {
    func(1, 1, 7);
    int t;
    while (cin >> t) {
        if (t == -1) break;
        for (int i = 1; i <= num[t]; i++) {
            for (int j = 1; j <= num[t]; j++) {
                if (ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }

    return 0;
}