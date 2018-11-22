#include <iostream>
using namespace std;
int main(void){
    int total, sum =0;
    cin >> total;
    for(int i=0;i<9;i++){
        int a;
        cin >> a;
        sum += a;
    }
    cout << total - sum << endl;
}
//Input
// 9850
// 1050
// 800
// 420
// 380
// 600
// 820
// 2400
// 1800
// 980

//Output
// 600