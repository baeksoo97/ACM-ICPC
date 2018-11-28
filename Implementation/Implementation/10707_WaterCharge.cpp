#include <iostream>
using namespace std;
int main(void){
    int a, b, c, d, p;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&p);
    int a_charge = a * p;
    int b_charge = p <=c ? b : b + (p-c) * d;
    printf("%d\n", a_charge <=b_charge? a_charge : b_charge);
}
//Input
// 9
// 100
// 20
// 3
// 10

//Output
// 90