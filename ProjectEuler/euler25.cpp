/*
 * @Descripttion: 斐波那契，大整数相加，
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-10 18:16:58
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-11 14:32:15
 */


#include<iostream>
using namespace std;

void func(int *n1, int *n2) {
    n2[0] = n1[0];//n2的长度可能短，要保证对齐n1的长度
    for (int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        if (n2[i] > 9) {
            n2[i + 1] += n2[i] / 10; //进位
            n2[i] %= 10;
            if (i == n2[0]) {
                n2[0]++; //长度 + 1
            }
        }
    }
}

int main() {
    int num[2][1005] = {{1,1},{1,1}};//第一个数长度是1，值是1；第二个数长度是1，值是1
    //num[0][0]和num[1][0]分别存储的是两个大整数的数字长度
    int a = 0, b = 1;//用于访问两个数组，把num[a],num[b]的数组取出来
    for (int i = 3; 1; i++) {
        func(num[a], num[b]);//将num[a]的值加进num[b]里
        if (num[b][0] >= 1000) {
            cout << i << endl;
            break;
        }
        swap(a, b);//把两个数循环加
    }

    return 0;
}
