/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-09 14:10:36
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-09 15:05:04
 */

#include<iostream>
#include<cstring>
using namespace std;

char s1[105], s2[105];
int n1[105], n2[105], ans[205];

int main() {
    cin >> s1 >> s2;
    n1[0] = strlen(s1), n2[0] = strlen(s2);
    
    //存储数字
    for (int i = 0, j = n1[0]; s1[i]; i++, j--) {
        n1[j] = s1[i] - '0';
    }
    for (int i = 0, j = n2[0]; s2[i]; i++, j--) {
        n2[j] = s2[i] - '0';
    }
    ans[0] = n1[0] + n2[0] - 1;//答案的长度

    //计算
    for (int i = 1; i <= n1[0]; i++) {
        for (int j = 1; j <= n2[0]; j++) {
            ans[i + j - 1] += n1[i] * n2[j];
        }
    }
    
    //处理进位
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0]++;
            } 
        } else if (i == ans[0] && ans[i + 1] != 0) {
            ans[0]++;
        }
    }
    //输出
    for (int i = ans[0]; i > 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}