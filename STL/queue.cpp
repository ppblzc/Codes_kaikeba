#include<iostream>
#include<queue>
using namespace std;

int main() {
   
    struct node {
        int num, cnt;
    };

    queue<node> que;
    que.push({1,10});//自定义结构的格式要求不高，加不加node都行
    que.push((node){2,9});
    que.push(node{3,9});
    cout << que.size() << endl;
    while (!que.empty()) {
        cout << que.front().num << " " << que.front().cnt << endl;
        que.pop();
    }
    /* 
    queue<int> q;
    q.push(66);
    q.push(77);
    q.push(88);
    cout << q.size() << endl;
    while (!q.empty()) {
        cout << q.front() << " " << q.back() << endl;
        q.pop();
    }
 */
    return 0;
}