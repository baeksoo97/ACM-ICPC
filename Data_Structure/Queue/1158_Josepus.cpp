#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int main(void){
    int n, m, cnt = 0;
    scanf("%d %d",&n,&m);
    queue <int> q;
    for(int i=1;i<=n;i++)
        q.push(i);
    cout << "<";
    while(!q.empty()){
        for(int i=0;i<m-1;i++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        cnt++;
        if(cnt == n)
            cout << q.front();
        else
            cout << q.front() << ", ";
        q.pop();
    }
    cout << ">" << endl;
}
//Input(<=5000)
//7 3

//Output
//<3, 6, 2, 7, 5, 1, 4>