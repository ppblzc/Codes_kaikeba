/*************************************************************************
	> File Name: 477.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 20 Mar 2021 02:29:38 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int main() {
    char s[105];
    cin >> s;
    int last = -1, ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U') {
            if (last == -1) {
                last = i;
            }else {
                ans = max(ans, i - last);
                last = i;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
