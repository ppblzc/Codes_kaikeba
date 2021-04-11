/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-11 14:50:53
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-11 15:39:05
 */

#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
//每个学生，有多个属性，建立结构体
struct student {
    int num, avg, cla, paper, m;
    string name;
    char off, west;
};

int n, all;
student stu[105];

int func(int x) {
    int t = 0;//该同学的奖金金额
    if (stu[x].avg > 80 && stu[x].paper >= 1) t += 8000;
    if (stu[x].avg > 85 && stu[x].cla > 80) t += 4000;
    if (stu[x].avg > 90) t += 2000;
    if (stu[x].avg > 85 && stu[x].west == 'Y') t += 1000;
    if (stu[x].cla > 80 && stu[x].off == 'Y') t += 850;
    return t;
}

//排序规则
bool cmp(const student &a, const student &b) {
    if (a.m == b.m) {
        return a.num < b.num;
    }
    return a.m > b.m;
}

int  main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        stu[i].num = i;
        cin >> stu[i].name >> stu[i].avg >> stu[i].cla >> stu[i].off >> stu[i].west >> stu[i].paper;
        stu[i].m = func(i);
        all += stu[i].m;
    }
    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl << stu[0].m << endl << all << endl;

    return 0;
}