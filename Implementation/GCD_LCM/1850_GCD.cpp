#include <stdio.h>
#include <iostream>
using namespace std;
#define lld long long int
lld GCD(lld a, lld b);
int main(void){
    lld a, b, gcd;
    scanf("%lld %lld",&a,&b);
    gcd = GCD(a, b);
    for(int i=0;i<gcd;i++)
        printf("1");
}
lld GCD(lld a, lld b){
    return b ? GCD(b, a%b) : a; 
}
//Input
// 500000000000000000 500000000000000002

//Output
// 11