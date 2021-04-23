/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-19 21:15:26
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-19 21:24:42
 */
#include<iostream>
#include<map>
#include<string>
using namespace std;

struct student{
    int num, cnt;
    string name;
} stu;
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%6d%s%d", &stu.num, &stu.name, &stu.cnt);
    }
    
    return 0;
}