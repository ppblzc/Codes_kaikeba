#include<stdio.h>

int main(){
    long long ans = 0;
    int a = 1, b = 2;
    while(b < 4000000){
        if(b % 2 == 0) ans += b;
        b = a + b;
        a = b - a;
    }
    //cout << ans << endl;
    printf("%ld",ans);
    return 0;
}