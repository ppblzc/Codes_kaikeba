/*
 * @Descripttion: priority_queue的使用
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-02 16:01:27
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-02 21:31:03
 */

#include<iostream>
#include<queue>
#include<string>
using namespace std;

struct node {
    int id, offset, next;//id,偏移量，下一次获得新闻的时间
    bool operator<(const node &b) const {//重载的固定格式,结构体内部重载小于号
        if (this->next == b.next) {//当两个节点的next相同时，优先弹出id小的节点
            return this->id > b.id;
        }
        return this->next > b.next;//自定义结构，优先队列节点，pop规则为：按next由小到大弹出
    }
};
int main() {
    int n;
    string t;
    priority_queue<node> que;
    while (cin >> t) {
        if (t[0] == '#') break;//循环终止，不再开始下一次
        int id, offset;
        cin >> id >> offset;
        que.push((node){id, offset, offset});

    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        node tmp = que.top();
        cout << tmp.id << endl;
        tmp.next += tmp.offset;//下一次推送的时间点
        que.push(tmp);
        que.pop();
    }
    return 0;
}

/*错误测试样例
2004 200
2005 300
#
5
*/