#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

int main() {
    set<int> s1;
    unordered_set<int> s2;
    for (int i = 0; i < 1000000; i++) {
        s1.insert(i);
    }
    return 0;
}