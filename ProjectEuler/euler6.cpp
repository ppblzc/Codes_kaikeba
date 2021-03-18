#include<iostream>
using namespace std;

int main() {
    int sum = 0, psum = 0;
    for (int i = 0; i <= 100; i++){
        sum += i;
        psum += i * i;
    }
    cout << sum * sum - psum << endl;
    return 0;
}