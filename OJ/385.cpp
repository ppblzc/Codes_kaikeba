/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-08 09:17:27
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-08 11:00:21
 */
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

//以每位乘客为实例，建立结构体
struct person {
    int t, c;//到达的时间、所属国籍
};
int nation[1000005];

int main() {
    queue<person> que;
    int n = 0;//船的个数
    int con = 0;//存储答案
    
    //cin >> n;
    scanf("%d",&n);
    //n行数据的输入
    for (int i = 0; i < n; i++) {
        int t, k;//当前船抵达的时间，船上的乘客数
        //cin >> t >> k;
        scanf("%d%d", &t, &k);
        while (!que.empty()) {//将不符合时间要求的人，出队 
            person tmp = que.front();
            if (t - tmp.t < 86400) break;
            que.pop();
            nation[tmp.c]--;
            if (nation[tmp.c] == 0) con--;
            
        }
        for (int j = 0; j < k; j++) {
            int tmp;
            //cin >> tmp;
            scanf("%d", &tmp);
            que.push({t, tmp});
            if (nation[tmp] == 0) con++;
            nation[tmp]++;
        }
        //cout << con << endl;
        printf("%d\n", con);
    }

    return 0;
}