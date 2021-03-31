#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
    unordered_map<string, int> m;
    m["123"] = 56788;
    m["asdf"] = 234;
    m["^&*"] = 8888;

    cout << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}