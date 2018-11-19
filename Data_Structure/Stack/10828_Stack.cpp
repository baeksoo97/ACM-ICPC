#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    int n;
    scanf("%d",&n);
    stack<int> st;
    string s;
    while(n--){
        int a;
        cin >> s;
        // cout << s <<" ";
        if( s== "push"){
            cin >> a;
            st.push(a);
        }
        else if(s == "pop"){
            if(!st.empty()){
                cout << st.top()<< endl;
                st.pop();
            }
            else{
                cout << "-1" <<endl;
            }
        }
        else if(s == "size"){
            cout << st.size() <<endl;
        }
        else if (s == "empty"){
            if(st.empty())
                cout << "1"<<endl;
            else
                cout << "0"<<endl;
        }
        else if (s=="top"){
            if (!st.empty())
                cout << st.top() <<endl;
            else    
                cout << "-1"<< endl;
        }
        
    }
}