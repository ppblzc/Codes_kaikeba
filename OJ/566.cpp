#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

int n, m;//共有n个人，m条上网记录
int cnt;//用来统计已出现的用户数
unordered_map<string, int> um;//当某位用户新增一条浏览记录时，定位该条记录应存放的位置，string是用户名，int表示在二维vector中处于第几行
//例如string == goodstudyer,int == 1;则goodstudyer用户的两条浏览记录都存在第一行
int main() {
    cin >> n >> m;
    vector<vector<string> > v(n, vector<string>{});//用来存储输出的内容,每个用户都是一个vector<string>,
    for (int i = 0; i < m; i++) {//遍历m条浏览记录
        string a, b;
        cin >> a >> b;//输入第2~m+1行内容，分别表示用户名和浏览的网页名
        if (um.count(a) == 0) {//当出现未统计过的的用户时，输出中新增一行数据，
            um[a] = cnt;//确定新用户a在第几行输出记录，即新增一行vector<string>
            v[cnt].push_back(a);//用户名
            v[cnt].push_back(b);//a用户浏览的网页名
            cnt++;
        } else { //非第一次出现的用户，直接在对应行的末尾追加一条记录
            v[um[a]].push_back(b);
        }
    }  
    for (int i = 0; i < n; i++) { //此时cnt与n相等，遍历输出
        for (int j = 0; j < v[i].size(); j++) {//j=0为用户名，j>=1为浏览记录
            if (j) cout << " ";//处理空格
            cout << v[i][j];
        }
        cout << endl;
    }  


    return 0;
}