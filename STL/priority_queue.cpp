#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int num, cnt;
    /* 
    //自定义结构比较大小，结构体内部重载小于号
    bool operator< (const node &b) const {
        return this->num < b.num;
    }
     */
};
//仿函数
struct func {
    bool operator() (const node &a, const node &b) {
        return a.num < b.num;
    }
};
int main() {
    priority_queue<node, vector<node>, func > q;
    q.push({1,99});
    q.push({2,-3});
    q.push({3,12});
    cout << "size: " << q.size() << endl;
    while (!q.empty()) {
        cout << q.top().num << " " << q.top().cnt << endl;
        q.pop(); 
    }


    /* 
    //priority_queue<int> q;//默认是大顶堆，堆顶是较大的元素，所以每次pop出的是当前堆中最大的元素
    priority_queue<int, vector<int>, greater<int> > q; //小顶堆,由小到大输出
    q.push(1);
    q.push(999);
    q.push(-3);
    cout << "size : " << q.size() << endl;
    while (!q.empty()) {
        cout << q.top() << endl;
        q.pop();
    } 
 */
    return 0;
}