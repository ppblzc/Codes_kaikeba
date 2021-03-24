/*************************************************************************
	> File Name: 481.cpp
    > 冰壶比赛
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 04:00:05 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int m[15][2], r;//m[i][0]第i局甲方得分，m[i][1]第i局乙方得分,r为得分限制距离

void print(int cnt) {
    int ans0 = 0, ans1 = 0;
    for (int i = 1; i < cnt; i++) {
        cout << m[i][0] << ":" << m[i][1] << endl;
        ans0 += m[i][0];
        ans1 += m[i][1];
    }
    cout << ans0 << ":" << ans1 << endl;
}

int main() {
    cin >> r;//第一行输入一个整数r
    for (int i = 1; i <= 10; i++) {//比赛至多进行10局
        int num0[10], num1[10];//每轮投8个球，记录各球距P点的距离
        for (int j = 0; j < 8; j++) {
            cin >> num0[j];
            if (num0[j] == -1 ) { //对弃权终止，进行判断
                print(i);
                return 0;
            }
        }
        for (int j = 0; j < 8; j++) {//输入8个球对应的距离
            cin >> num1[j];
        }
        sort(num0, num0 + 8);//排序找出，何方的球，距离目标P最近
        sort(num1, num1 + 8);
        if (num0[0] < num1[0]) {//其中一球距离目标最近的一方在该局中才可得分，甲方得分
            for (int j = 0; j < 8 && num0[j] < num1[0] && num0[j] <= r; j++) {//根据计分规则，甲方可加的分数
                m[i][0]++;
            }
        }else {//乙方得分
            for (int j =0; j < 8 && num1[j] < num0[0] && num1[j] <= r; j++) {//根据计分规则，乙方可加的分数
                m[i][1]++;
            }
        }
    }
    print(11);

    return 0;
}
