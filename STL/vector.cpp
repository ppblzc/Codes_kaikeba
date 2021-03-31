#include<iostream>
#include<vector>
using namespace std;

int main() {
    //扩容的实现
    vector<int> v;
    int cnt = -1;
    for (int i = 1; i <= 100000; i++) {
        if (cnt != v.capacity()) {
            cout << i << " : " << v.capacity() << endl;
            cnt = v.capacity();
        }
        v.push_back(i);
    }


    //二维的实现
    /*
    vector<vector<int> > v(10, vector<int>(10, 9));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    /*
    vector<int> v(10, 0);
    v.push_back(99);
    v.push_back(8);
    v.push_back(56);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " ;
    }
    */
    cout << endl;


    return 0;
}