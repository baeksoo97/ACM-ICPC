#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int l, a, b, c, d;
    scanf("%d %d %d %d %d", &l, &a, &b, &c, &d);
    printf("%d\n", l - max(a%c!=0 ? a/c+1:a/c, b%d!=0?b/d+1:b/d));
}