/*
 * @Descripttion: 排序
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-07 16:13:04
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-07 17:11:58
 */

#include<iostream>
#include<algorithm>
using namespace std;

struct stu {
    int score, cnt;
};

bool cmp(stu &a, stu &b) {//自定义sort用到的排序规则,
    if (a.score == b.score) {
        return a.cnt < b.cnt;
    }
    return a.score > b.score;
}

int main() {
    int n;
    stu s[205];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i].score >> s[i].cnt;
    }
    
    sort(s, s + n, cmp);
    for (int i = 0; i < n; i++) {
        int x = 0;
        for (int j = 0; j < i; j++){
            if (s[j].cnt < s[i].cnt) {
                x++;
            }
        }
        cout << x << endl;
    }
    return 0;
}