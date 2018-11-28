#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(void){
    int n, total = 0;
    scanf("%d",&n);
    int map[101][101] = {0,};
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d %d",&a,&b);
        for(int h=a;h<a+10;h++){
            for(int w=b;w<b+10;w++){
                if(map[h][w] == 1)
                    continue;
                map[h][w] = 1;
                total++;
            }
        }
    }
    printf("%d\n",total);
}
//Input
// 3
// 3 7
// 15 7
// 5 2

//Output
// 260
//2차원 배열을 1사분면에 올려놓는다고 생각하자.
