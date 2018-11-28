#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
int main(void){
    int sum = 0;
    vector < pair<int, int> > v;
    vector < int > order;
    for(int i = 0;i<8;i++){
        int a;
        scanf("%d",&a);
        v.push_back(make_pair(a,i+1));
    }
    sort(v.rbegin(), v.rend());
    for(int i=0;i<5;i++){
        sum += v[i].first;
        order.push_back(v[i].second);
    }
    sort(order.begin(), order.end());
    
    printf("%d\n",sum);
    for(int i=0;i<5;i++)
        printf("%d ", order[i]);
    
}
//Input
// 20
// 30
// 50
// 48
// 33
// 66
// 0
// 64

//Output
// 261
// 3 4 5 6 8