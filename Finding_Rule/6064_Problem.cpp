#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(void){
    int test;
    scanf("%d",&test);
    while(test--){
        int m, n, x, y, k = 0;
        scanf("%d %d %d %d",&m,&n,&x,&y);
        if(m > n){
            swap(m, n);
            swap(x, y);
        }
        int diff = abs(m-n);
        if(diff == 0){
            if ( x > m || y > n || x!= y)
                printf("-1\n");
            else   
                printf("%d\n",x);
        }
        else{
            if (((n+x)-y) % diff || x > m || y > n)
                printf("-1\n");
            else
                printf("%d\n",((n+x)-y)/diff * m + x);
        }
    }
}
//Input
// 3
// 10 12 3 9
// 10 12 7 2
// 13 11 5 6

//Output
// 33
// -1
// 83