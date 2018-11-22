#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.compare(b) > 0)
        cout << a << endl;
    else
        cout << b << endl;
}
//Input
//734 893

//Output
//43711