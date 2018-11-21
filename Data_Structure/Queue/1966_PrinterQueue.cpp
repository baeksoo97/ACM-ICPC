#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(void){
    int test;
    scanf("%d",&test);
    while(test--){
        vector <int> v;
        queue <pair<int,int> > q; 
        int n, m, idx = 0, cnt = 0;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            q.push(make_pair(i, num));
            v.push_back(num);
        }
        sort(v.begin(), v.end(), greater<int>());
        while(1){
            pair <int,int> p = q.front();
            q.pop();
            if(p.second == v[idx]){
                cnt++;
                if(p.first == m)
                    break;
                else
                    idx++;
            }
            else
                q.push(p);
        }
        cout << cnt << endl;
    }
}
//Input
// 3
// 1 0
// 5
// 4 2
// 1 2 3 4
// 6 0
// 1 1 9 1 1 1

//Output
// 1
// 2
// 5
