/*************************************************************************
	> File Name: 506.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 06:44:26 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int cnt, num;//cnt为同学编号，num为打水时间
};

node stu[35];
int n;//总人数

bool cmp (const node &a, const node &b) {//排序规则：打水时间短的人排在前
    return a.num < b.num;
}

int main() {
    cin >> n;
    for (int i =1; i <= n; i++) {//同学的编号是从1开始的
        cin >> stu[i].num;//输入每位同学的打水时间
        stu[i].cnt = i;//为每位同学编号
    }
    sort(stu + 1, stu + n + 1, cmp);//注意排序的起始与终止位置 
    int sum = 0, now = 0;//sum是所有同学的总打水时间，now是第i位同学的总等待时间
    for (int i= 1; i <= n; i++){
        if (i != 1) {//第一个数字前没有空格
            cout << " ";
        }
        cout << stu[i].cnt;//输出排序后的同学编号
        sum += now;//每个同学的等待时间，累加进总的时间
        now += stu[i].num;//第i + 1个同学的等待时间，是在第i个同学的等待时间 + i同学的打水时间
    }
    cout << endl;
    printf("%.2f\n", (double)sum / n);//输出最小平均等待时间

    return 0;
}
