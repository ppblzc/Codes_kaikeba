/*
 * @Descripttion: 简单的动态规划问题
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-10 13:08:44
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-10 13:50:40
 */

#include<iostream>
using namespace std;

long long ans[25][25];

int main () {
   /*
    //右上角从[1,1]开始，防止越界，最外圈设置保护“0”
    for (int i = 1; i <= 21; i++) {
        for (int j = 1; j <= 21; j++) {
            if (i == 1 && j == 1) {
                ans[i][j] = 1;//赋初值
                continue;
            }
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];//本题采用递推，也可采用“递归 + 记忆化”
        }
    }
    cout << ans[21][21] << endl;
    */
   
   //方法二
   long long fin = 1;
   for (int i = 40, j = 1; i > 20; i--, j++) {
       fin *= i;
       fin /= j;
   }
   cout << fin << endl;
    return 0;
}