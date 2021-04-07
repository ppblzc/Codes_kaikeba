/*
 * @Descripttion: oi576.最大收益
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-07 14:01:09
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-07 15:27:26
 */

#include<iostream>
#include<map>
using namespace std;

int n, k;
map<string, int> profit, num;

int main() {
    cin >> n >> k;
    long long ans = 0;//变量声明，没有放在全局区的话，需要手动赋值
    for (int i = 0; i < n; i++) {
        string t;//存储商品名称
        int t2, t3;//单件物品的利润、库存量
        cin >> t >> t2 >> t3;
        profit[t] = t2;
        num[t] = t3;
    }
    for (int i = 1; i <= k; i++) {
        string t;//商品名称
        int t3;//订单所需数量
        cin >> t >> t3;//订单商品名称、所需数量
        if (t3 > num[t]) {
            cout << "-" << i << endl;
            return 0;
        } else {
            num[t] -= t3;
            ans += t3 * profit[t];
        }
    }
    cout << ans << endl;

    return 0;
}