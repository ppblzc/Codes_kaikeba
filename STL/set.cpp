#include<iostream>
#include<set>

using namespace std;

struct node{
    int num, cnt;
    bool operator< (const node &b) const {
        return this->cnt < b.cnt;//根据自身需求，选定使用num / cnt进行排序
    }
};

int main() {
    set<node> s;
    s.insert({1,-99});
    s.insert({2,88});
    s.insert({3,22});
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << it->num << " " << it->cnt << endl;//指针是间接引用
    }
    /* set<int> s;
    s.insert(7);
    s.insert(99);
    s.insert(-23);
    s.insert(128);
    cout << "size: " << s.size() << endl;
    if (s.count(128)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    s.erase(128);
    if (s.count(128)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    } 
    //使用迭代器输出所有元素
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    */
    return 0;
}