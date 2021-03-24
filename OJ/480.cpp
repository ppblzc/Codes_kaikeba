/*************************************************************************
	> File Name: 480.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 03:28:59 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//对每一局的情况，建立自定义结构
struct node {
    char s[4];//当前局的情况
    int num1, num2, flag;//num1为本轮第一球的得分，num2为两球的总得分，flag标定是否加分，0不加，1加一球，2加两球
};

node m[15];//最多12局

int main() {
    for (int i = 1; cin >> m[i].s; i++) {
        if (m[i].s[0] == '/') {//本轮一球全中，加两球
            m[i].num1 = 10;
            m[i].num2 = 10;
            m[i].flag = 2;
        } else if (m[i].s[1] == '/') {//本轮第一球未全部击倒，通过第二球全部击倒,加一球
            m[i].num1 = m[i].s[0] - '0';
            m[i].num2 = 10;
            m[i].flag = 1;
        } else { //本轮两球过后，还未全部击倒，没有加分
            m[i].num1 = m[i].s[0] - '0';
            m[i].num2 = m[i].num1 + m[i].s[1] - '0';
        }
    }

    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        ans += m[i].num2;//本轮的原始分
        if (m[i].flag == 1) { //加下一轮的第一球的得分
            ans += m[i + 1].num1;
        }else if (m[i].flag == 2) { //加下两球的得分
            if (m[i + 1].flag == 2) { //如果下一轮的第一球也全中
                ans += 10 + m[i + 2].num1;//第一轮的原始分 + 第二轮的原始分 + 第三轮的首球分
            } else {
                ans += m[i + 1].num2;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
