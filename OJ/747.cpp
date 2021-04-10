/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-09 15:48:39
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-09 15:59:26
 */
#include<iostream>
#include<cstring>
using namespace std;

char s1[105], s2[105];
int n1[105], n2[105], ans[105];

int main() {
    //存
    cin >> s1 >> s2;
    n1[0] = strlen(s1);
    n2[0] = strlen(s2);
    
    for (int i = 0, j = n1[0]; s1[i]; i++, j--) {
        n1[j] = s1[i] - '0';
    }
    for (int i = 0, j = n2[0]; s2[i]; i++, j--) {
        n2[j] = s2[i] - '0';
    }
    //计算
    return 0;
}