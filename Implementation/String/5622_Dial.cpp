#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    string s;
    int sum = 0;
    cin >> s;
    //012->2, 345->3, 678->4,,,
    string dial[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    for(int i=0;i<s.length();i++){
        int sec;
        if (s[i]<'P')
            sec = (s[i] - 'A')/3 + 2;
        else if('P'<=s[i] && s[i]<'T')
            sec = 7;
        else if('T'<=s[i] && s[i]<'W')
            sec = 8;
        else   
            sec = 9;
        sum += sec;
    }
    sum += s.length();
    cout << sum << endl;
}

//Input
//UNUCIC

//Output
//36