#include <iostream>
using namespace std;
int main(void){
    int a, b;
    int sum_a =0, sum_b= 0;
    for(int i=0;i<4;i++){
        cin >> a;
        sum_a += a;
    }
    for(int i=0;i<4;i++){
        cin >> b;
        sum_b += b;
    }
    printf("%d\n", sum_a >= sum_b? sum_a : sum_b);

}
//Input
// 100 80 70 60
// 80 70 80 90

//Output
// 320