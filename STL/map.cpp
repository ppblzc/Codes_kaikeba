#include<iostream>
#include<string>
#include<utility>
#include<map>
using namespace std;

int main() {
    map<string, int> m;
    m.insert(make_pair("No.1",7788));
    m.insert(make_pair("No.2",-234));
    m.insert(make_pair("No.3",3344));
    cout << "size: " << m.size() << endl;
    cout << m["No.3"] << endl;
    m["No.4"] = 99999;
    cout << m["No.4"] << endl;
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}