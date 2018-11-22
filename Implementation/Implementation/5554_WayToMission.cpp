#include <iostream>
using namespace std;
int main(void){
    int sum = 0;
    for(int i=0;i<4;i++){
        int a;
        scanf("%d",&a);
        sum+= a;
    }
    cout << sum/60 << endl;
    cout << sum%60 << endl;
}
//Input
// 31
// 34
// 7
// 15

//Output
// 3
// 43