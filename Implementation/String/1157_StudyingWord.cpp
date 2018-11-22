#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    string s;
    getline(cin, s);
    int alphabet[26] = {0,};
    int isDuplicate = 0;
    for(int i=0;i<s.length();i++){
        int idx = 0;
        if (s[i] >= 'A' &&s[i] <='Z')
            idx = s[i] - 'A';
        else if (s[i]>='a' && s[i]<='z')
            idx = s[i] - 'a';
        alphabet[idx]++;
    
    }
    int max = 0, max_idx = -1;
    for(int i=0;i<26;i++){
        if(max < alphabet[i]){
            max = alphabet[i];
            max_idx = i;
        }
    }
    for(int i=0;i<26;i++)
        if (max == alphabet[i] && max_idx != i){
            isDuplicate = 1;
            
    if(isDuplicate)
        cout << "?" <<endl;
    else
        cout << char(max_idx +'A') <<endl;
    
}
//Input
// Mississipi

//Output
// ?