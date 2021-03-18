#include<iostream>
using namespace std;

int func(int);

int main(){
    int ans = 0;
    for (int i = 100; i < 1000; i++){
        for (int j = i; j < 1000; j++){
            if (func(i * j)){
                ans = max(ans, i * j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//回文数判断
int func(int n) {
    int raw = n, t = 0;
    while(n){
        t = t * 10 + n % 10;
        n /= 10;
    }
    return raw == t;
}