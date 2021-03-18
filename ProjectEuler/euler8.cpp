#include<iostream>
using namespace std;

char str[1005];

int main() {
    long long ans = 0, now = 1, zero_cnt = 0;
    cin >> str;
    for (int i = 0; str[i]; i++){
        //先完成乘上新进入的数
        if (i < 13){
            now *= str[i] - '0';
        }else if (str[i] != '0') {
            now *= str[i] - '0';
        }else {
            zero_cnt++;
        }
        //除去末尾的数，出窗口
        if (i >= 13) {
            if (str[i - 13] != '0') {
                now /= str[i -13] - '0';
            }else {
                zero_cnt--;
            }
        }
        //更新答案
        if (i >= 13 && zero_cnt == 0) {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}

