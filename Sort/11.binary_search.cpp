#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary_search(int *arr, int n, int x){
    int head = 0, tail = n - 1, mid;
    while(head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid -1;
    } 
    return -1;
}

//11111111110000000000查找最后一个1
int binary_search1(int *arr, int n, int x){
    int head = -1, tail = n - 1, mid;//head,虚拟位
    while (head < tail) {
        mid = (head + tail) >> 2;
        if (arr[mid] == x) head = mid;
        else tail = mid - 1;
    }
    return head == -1 ? -1 : head;

}

//0000000000001111111111111111111
int binary_search2(int *arr, int n, int x){
    int head = 1, tail = n, mid;//
}

void randint(int *arr, int n) {
    while (n--) arr[n] = rand() % 100;
    return ;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main(){
    #define MAX_N 10
    srand(time(0));
    int arr[MAX_N];
    randint(arr, MAX_N);
    
    return 0;
}