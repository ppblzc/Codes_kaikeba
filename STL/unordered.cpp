#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> m;
    m["no.1"] = 345;
    m["111"] = 789;
    m["no.2"] = -33;
    m["no.3"] = 22;
    cout << "size: " << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}