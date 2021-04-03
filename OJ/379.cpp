#include<iostream>
#include<stack>
using namespace std;

stack<int> cnt, mmax;//cnt表示仓库内每批货物的个数，mmax的栈顶用来存储最大的个数
int n; //操作次数
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t; //用来标记是0：入库， 1：出库， 2：查询
        cin >> t;
        switch (t)
        {
        case 0:{
            cin >> t;//入库的数量
            cnt.push(t);
            if (cnt.size() == 1) mmax.push(t);//首次入库
            else mmax.push(max(mmax.top(), t));
        }break;
        case 1:{
            if (!cnt.empty()) {
                cnt.pop();
                mmax.pop();
            }
        }break;
        case 2:{
            if (!mmax.empty()) cout << mmax.top() << endl;
            else cout << 0 << endl;
        }break;
        
        }
    }

    return 0;
}