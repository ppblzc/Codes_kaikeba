#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> que;//使用队列模拟 约瑟夫环
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        que.push(i);//构建队列
    }
    int now = 1;//当前的报数
    while (que.size() != 1) {
        if (now != m) {
            que.push(que.front());//没有报中m，则放到队尾
            now++;//报数依次增加
        }else {
            now = 1;//猜中m后，下一个人从1开始
        }
        que.pop();
    }
    cout << que.front() << endl;//输出最后一个人
    return 0;

}