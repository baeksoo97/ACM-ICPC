#include <iostream>
#include <string>
using namespace std;
int main(void){
    int test;
    scanf("%d",&test);
    while(test--){
        int r;
        string s, p= "";
        scanf("%d",&r);
        cin >> s;
        for(int i=0;i<s.length();i++){
            for(int j=0;j<r;j++)
                p.append(sizeof(char), s[i]);
            // cout << p << endl;
        }
        cout << p << endl;
    }
}
//Input
// 2
// 3 ABC
// 5 /HTP

//Output
// AAABBBCCC
// /////HHHHHTTTTTPPPPP