#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void){
    int test;
    scanf("%d",&test);
    string s;
        
    while(test--){
        cin >> s;
        stack <char> st;
        int isVPS = 1;
        for(int i=0;i<s.length();i++){
                // printf("%d : %c\n", i, s[i]);
            if((st.empty() || st.top() == '(') && s[i] == '('){
                // printf("push\n");
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == '(' && s[i] == ')'){
                // printf("pop\n");
                st.pop();
            }
            else if(st.empty() && s[i]==')'){
                isVPS =0;
                cout << "NO" << endl;
                break;
            }

        }
        if(isVPS && st.empty())
            cout << "YES" <<endl;
        else if(!st.empty())
            cout << "NO" <<endl;
    }
}
//Input
// 6
// (())())
// (((()())()
// (()())((()))
// ((()()(()))(((())))()
// ()()()()(()()())()
// (()((())()(

// Output
// NO
// NO
// YES
// NO
// YES
// NO