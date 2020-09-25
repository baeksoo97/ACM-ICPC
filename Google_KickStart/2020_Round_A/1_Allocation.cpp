#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int test;
    scanf("%d", &test);
    for(int t = 1; t <= test; t++){
        int a, b;
        scanf("%d %d", &a, &b);
        vector <int> pay(a);
        for(int i = 0; i < a; i++){
            scanf("%d", &pay[i]);
        }
        sort(pay.begin(), pay.end());
        int sum = 0, answer = 0;
        for(int i = 0; i < a; i++){
            sum += pay[i];
            if (sum <= b){
                answer++;
            }
            else{
                break;
            }
        }
        printf("Case #%d: %d\n", t, answer);
    }
    return 0;
}