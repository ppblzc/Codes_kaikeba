#include<stdio.h>
#include<stdlib.h>

typedef struct Stack {
    char *val;
    int p, maxSize;
} Struct;

int isVaild(char *str, int n);

int main(){
    #define MAX_N 20
    char *str;
    int n = MAX_N;
    scanf("%s", &str);
    isVaild(str, n);
    return 0;
}