#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int test = 3;
    while(test--){
        int a, b, c, d, sum = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum = a+b+c+d;
        if(sum == 3)
            printf("A\n");
        else if(sum == 2)
            printf("B\n");
        else if(sum == 1)
            printf("C\n");
        else if(sum == 0)
            printf("D\n");
        else if(sum == 4)
            printf("E\n");
    }
}