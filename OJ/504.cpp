/*************************************************************************
	> File Name: 504.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 06:14:02 PM CST
 ************************************************************************/
//思路：小数在前，大数在后，删掉后面的大数
#include<iostream>

using namespace std;

int main() {
    string s;//以字符串形式输入目标数，删除会用到replace方法
    cin >> s;
    int n;//删除数字的个数
    cin >> n;
    for (int i = 0; i < n; i++) {
        int ind = s.size() - 1;
        for (int j = 1; j < s.size(); j++) {
            if (s[j - 1] > s[j]){
                ind = j - 1;
                break;
            }
        }
        s.replace(ind, 1, "");
    }

    int flag = 0;//flag的作用是去掉前置0，对s[i]遍历，出现第一个 s[i] != '0' 时才开始输出
    // flag == 0 是前置0判断模式
    // flag == 1 是正常输入模式
    for (int i = 0; i < s.size(); i++){
        if (flag == 1) {
            cout << s[i];
        } else if (s[i] != '0') {//flag == 0时
            cout << s[i];
            flag = 1;
        }
    }
    if (flag == 0) cout << 0;//经过循环，flag仍然还未置为 1，说明全部为前置零，输出0
    cout << endl;
    return 0;
}
