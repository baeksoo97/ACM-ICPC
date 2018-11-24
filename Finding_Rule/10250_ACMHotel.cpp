#include <iostream>
using namespace std;
int main(void){
    int test;
    scanf("%d",&test);
    while(test--){
        int h, w, n;
        scanf("%d %d %d",&h,&w,&n);
        int x = (n-1) % h + 1;
        int y = (n-1) / h + 1;
        printf("%d%02d\n", x, y);
   }
}
//Input
// 2
// 6 12 10
// 30 50 72

//Output
// 402
// 1203