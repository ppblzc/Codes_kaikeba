/*************************************************************************
	> File Name: 479.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 02:55:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//s11\s21表示在两种计分模式下，总比赛局数,为了满足输出的格式要求
int s11[10005][2], s21[5005][2], cnt11, cnt21;

void print() {
    for (int i = 0; i <= cnt11; i++) {
        cout << s11[i][0] << ":" << s11[i][1] << endl;
    }
    cout << endl;
    for (int i = 0; i <= cnt21; i++) {
        cout << s21[i][0] << ":" << s21[i][1] << endl;
    }
}

int main() {
    char s[30];//每行的字符输入
    while (cin >> s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'E') {
                print();
                return 0;
            }
            if (s[i] == 'W') {
                s11[cnt11][0]++;
                s21[cnt21][0]++;
            }else {          //即s[i] == 'L'
                s11[cnt11][1]++;
                s21[cnt21][1]++;
            }
            if ((s11[cnt11][0] >= 11 || s11[cnt11][1] >= 11) && abs(s11[cnt11][0] - s11[cnt11][1]) >= 2) {
                cnt11++;
            }
            if ((s21[cnt21][0] >= 21 || s21[cnt21][1] >= 21) && abs(s21[cnt21][0] - s21[cnt21][1]) >= 2) {
                cnt21++;
            }
        }
    }


    return 0;
}
