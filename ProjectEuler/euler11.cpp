#include<iostream>
using namespace std;

int num[30][30], ans;

int main() {
    for (int i = 5; i < 25; i++){
        for (int j = 5; j < 25; j++){
            cin >> num[i][j];
        }
    }
    
    return 0;
}