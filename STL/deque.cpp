#include<iostream>
#include<deque>
using namespace std;
//底层存储的是指针
int main() {
    deque<int> q;
    q.push_back(3);//从尾部入队
    q.push_back(4);
    q.push_back(5);
    q.push_front(6);//从头部入队
    q.push_front(7);
    while (!q.empty()) {
        cout << q.front() << " " << q.back() << endl;
        q.pop_back();//从尾部出队
    }

    return 0;
}