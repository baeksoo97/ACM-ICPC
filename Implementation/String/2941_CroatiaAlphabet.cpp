#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    cin >> s;
    string croatia[7] = {"c=", "c-", "d-", "lj", "nj", "s=", "z="};
    int num_croatia = 0;
    while(s != ""){
        int sub_num = 0;
        string sub_str2 = s.substr(0,2);
        string sub_str3 = s.substr(0,3);

        for(int i=0;i<7;i++){
            if (sub_str2 == croatia[i]){
                sub_num = 2;
                break;
            }
        }
        if(sub_num == 0 && sub_str3 == "dz=")
            sub_num = 3;
        
        if(sub_num == 0)
            sub_num = 1;
        
        s.erase(0,sub_num);
        num_croatia++;
    }
    cout << num_croatia << endl;
}
//Input
//ljes=njak

//Output
//6