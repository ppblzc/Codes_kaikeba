#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<string> sta;
    sta.push("123");
    sta.push("chen");
    sta.push("ze");
    sta.push("lin");
    cout << sta.size() << endl;
    while (!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }
    return 0;
}