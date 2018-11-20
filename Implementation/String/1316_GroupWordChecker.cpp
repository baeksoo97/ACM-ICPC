#include <iostream>
#include <string>
using namespace std;
int main(void){
    int n, cnt = 0;
    scanf("%d",&n);
    for(int t = 0;t<n;t++){
        string s;
        cin >> s;
        int word[27] ={0,}, prev= s[0]; 
        for(int i=0;i<s.length();i++){
            int now = s[i] - 'a';
            if(word[now]!=0 && prev != now){
                cnt++;
                break;
            }
            else
                word[now] += 1;
            prev = now;
        }
    }
    cout << n-cnt << endl;
}
//Input
// 3
// happy
// new
// year

//Output
//3

//Input
// 4
// aba
// abab
// abcabc
// a

//Output
//1