#include <iostream>
using namespace std;
int main(void){
    int n;
    scanf("%d",&n);
    int sum = 0;
    while(n--){
        int a;
        scanf("%d",&a);
        if(a)
            sum++;
        else
            sum--;
    }
    if(sum > 0)
        printf("Junhee is cute!\n");
    else
        printf("Junhee is not cute!\n");
}
//Input 
// 3 1 0 0

//Output
//Junhee is not cute!