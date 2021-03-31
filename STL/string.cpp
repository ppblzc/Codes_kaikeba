#include<iostream>
#include<string>

using namespace std;

int main() {
    string str = "ABCDEF";
    cout << "原始字符串：" << str << endl; 
    cout << str.size() << endl;
    cout << str.find("DE") << endl;
    cout << (int)str.find("DE", 5) << endl;
    cout << "从下标为1的位置截取长度为的字符串：" << str.substr(1, 2) << endl;
    cout << str.insert(1, "aaa") << "新长度：" << str.size() << endl;
    str.replace(1, 3, "xxx");
    cout << str << endl;
    cout << "使用getline实现行输入，在下方输入字符串，并使用换行：" << endl;
    getline(cin, str);
    cout << str << endl;
    return 0;
}