#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

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
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == x) head = mid;
        else tail = mid - 1;
    }
    return head == -1 ? -1 : head;

}

//0000000000001111111111111111111    查找第一个1
int binary_search2(int *arr, int n, int x){
    int head = 1, tail = n, mid;//tail为虚拟位
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (arr[mid] == x) tail = mid;
        else head = mid + 1;
    }
    return head == n ? -1 : head;
}

/*
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
*/

int main(){
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[10] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
    P(binary_search(arr1, 10, 7));
    P(binary_search1(arr2, 10, 1));
    P(binary_search2(arr3, 10, 1));
    return 0;
}