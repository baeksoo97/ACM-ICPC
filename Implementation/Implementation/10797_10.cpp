#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int num;
    scanf("%d",&num);
    int sum = 0;
    for(int i=0;i<5;i++){
        int a;
        scanf("%d",&a);
        if(num == a)
            sum ++;
    }
    printf("%d\n",sum);
}
//Input
// 5
// 1 3 0 7 4

//Output
//0