/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-09 18:48:44
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-09 18:58:42
 */

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int ans = 0;
    int w, n, num[30005];
    cin >> w >> n;
    for (int i = 0;i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    for (int i = n - 1; i >= 0; i--) {
        if (num[i] == 0) continue;
        ans++;
        for (int j = i - 1; j >= 0; j--) {
            if (num[j] != 0 && num[i] + num[j] <= w) {
                num[j] = 0;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}