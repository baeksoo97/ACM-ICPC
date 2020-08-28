#include <iostream>
using namespace std;
int main(void){
    int n, sum = 1, idx = 1;
    scanf("%d",&n);
    while(1){
        if(n <= sum){
            cout << idx << endl;
            break;
        }
        sum += 6 * (idx++);
    }
}
//Input
// 13

//Output
// 3
