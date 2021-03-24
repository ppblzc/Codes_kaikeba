
#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    char s[105];
    scanf("%s", s);
    int last = -1, ans = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            if (last != -1) ans = max(ans, i - last);
            last = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}