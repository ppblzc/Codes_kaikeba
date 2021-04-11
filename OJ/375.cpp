/*
 * @Descripttion: 自定义结构体的排序规则 cmp
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-11 15:51:54
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-11 17:43:34
 */
#include<iostream>
#include<algorithm>
using namespace std;

struct student{
    int num, c, m, e, all;
};

int n;
student stu[305];

bool cmp(const student &a, const student &b) {
    if (a.all == b.all){
        if (a.c == b.c) {
            return a.num < b.num;
        }
        return a.c > b.c;
    }
    return a.all > b.all;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].c >> stu[i].m >> stu[i].e;
        stu[i].all = stu[i].c + stu[i].m + stu[i].e;
        stu[i].num = i + 1;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 5; i++) {
        cout << stu[i].num << " " << stu[i].all << endl;
    }
    return 0;
}