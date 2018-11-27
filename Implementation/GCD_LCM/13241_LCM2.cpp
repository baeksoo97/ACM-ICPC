#include <stdio.h>
#include <iostream>
using namespace std;
#define lld long long int

lld GCD(lld a, lld b);
int main(void){
    lld a, b, temp;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n", a*b/GCD(a, b));
    
}
lld GCD(lld a, lld b){
    return b ? GCD(b, a%b) : a;
}
//Input
// 121 199

//Output
// 24079