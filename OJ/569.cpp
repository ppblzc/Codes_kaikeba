#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

struct node
{
    double v, c, salt;
};

int main() {
    stack<node> sta;
    double v0, c0, salt0;
    cin >> v0 >> c0;
    salt0 = v0 * c0 / 100;//把溶质的质量求出来，方便计算
    int n;//操作次数
    char act;//P表示导入溶液，Z表示撤销操作
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> act;
        if (act == 'P') {
            double vt, ct, saltt;//每次添加时，液体的体积与浓度
            cin >> vt >> ct;
            saltt = vt * ct / 100;
            v0 += vt;
            salt0 += saltt;
            sta.push({vt, ct, saltt});

        }
        if (act == 'Z') {
            if (!sta.empty()) {
                v0 -= sta.top().v;
                salt0 -= sta.top().salt;
                sta.pop();
            }
        }
        printf("%d %.5f\n", (int)v0, salt0 / v0 * 100);
    }
    return 0;
}