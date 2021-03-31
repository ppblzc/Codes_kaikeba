#include<iostream>
#include<queue>

using namespace std;

int main() {
    queue<int> que;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    int now = 1;
    while (que.size() != 1) {
        if (now != m) {
            que.push(que.front());
            now++;
        }else {
            now = 1;
        }
        que.pop();
    }
    cout << que.front() << endl;
    return 0;

}