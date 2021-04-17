/*
 * @Descripttion: 
 * @Author: Arthur Lin
 * @version: 
 * @Date: 2021-04-16 08:28:31
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-04-16 09:22:34
 */
#include<cstdio>
#include<string>
#include<map>
using namespace std;

map<string, bool> nmap;
int cnt = 1;//体现回溯

void func() {
    if 
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        string name;
        scanf("%s", &name);
        nmap.insert(make_pair(name, true));
    }
    for (int i = 0; i < m; i++) {
        string t;
        scanf("%s", &t);
        nmap[t] = false;
    }
    for (auto it = nmap.begin(); it != nmap.end(); it++) {
        if (it -> second == true) {
            func();
        }
    }


    return 0;
}