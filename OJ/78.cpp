/*
 * @Descripttion: 大整数加法
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-09 09:36:22
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-09 10:23:48
 */

#include<iostream>
#include<cstring>

using namespace std;
char s1[105], s2[105];//下标从0开始，由高位到低位，存储原数字
int num1[105], num2[105], sum[105];//num[0]存储位长，num[1]~num[n]由低位到高位存储原数字

int main() {
    cin >> s1 >> s2;
    num1[0] = strlen(s1);
    num2[0] = strlen(s2);
    
    //把字符数组里的数存储进整型数组，从num[1]开始存储个位数
    for (int i = 0, j = num1[0]; s1[i]; i++, j--) {
        num1[j] = s1[i] - '0';
    }
    for (int i = 0, j = num2[0]; s2[i]; i++, j--) {
        num2[j] = s2[i] - '0';
    }
    //求和
    sum[0] = max(num1[0], num2[0]);//sum[0]用来存储答案可能的长度，先选取更长的数字为基准
    for (int i = 1; i <= sum[0]; i++) {
        sum[i] = num1[i] + num2[i];
    }
    //处理进位
    for (int i = 1; i < sum[0]; i++) {
        if (sum[i] > 9) {
            sum[i + 1] += sum[i] / 10; //针对加法可以写作 sum[i + 1] += 1;
            sum[i] %= 10;
            //最高位进位会触发答案长度变长
            if (i == sum[0]) {
                sum[0]++;
            }
        }
    }
    //输出
    for (int i = sum[0]; i > 0; i--) {
        cout << sum[i];
    }
    cout << endl;
    return 0;
}