#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string, int> m;//存储每个单词与其对应的次数,map为有序的，字典序小的排在前
string ans;//最终保留的答案，词频最高的那个单词
int cnt;//答案对应的频数

int main() {
    string str;//实际输入的内容
    while (cin >> str) {
        //对单词进行小写统一
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 'a' - 'A';
            }
        }
        m[str]++;
    } //实现对各个单词的词频统计，键值对

    //遍历找出词频最高的单词，分别存入ans, cnt
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > cnt) {
            ans = it->first;
            cnt = it->second;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}