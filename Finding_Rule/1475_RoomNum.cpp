#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    string s;
    int sum = 0, num[10] = {0,};
    cin >> s;
    for(int i=0;i<s.length();i++){
        int idx = s[i] - '0';
        num[idx]++;
    }
    int check = num[6] + num[9];
    check = check%2 == 1 ? check/2+1 : check/2;
    num[6] = check;
    num[9] = check;
    sort(num, num + 10);
    cout << num[9] << endl;
}
//Input
// 9999

//Output
// 2