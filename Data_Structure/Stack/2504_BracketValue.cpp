#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
    string s;
    cin >> s;
    stack <char> st;
    stack <pair<char, int> > st_oper;
    int isWrong = 0, isErase = 0;
    int score = 0;
    for(int i=0;i<s.length();i++){
        if(st.empty()){
            if(s[i] == ')' || s[i] == ']'){
                isWrong = 1;
                break;
            }
            else{
                st.push(s[i]);
                isErase = 0;
            }

        }
        else{
            if(st.top() == '('){
                if(s[i] == ')'){
                    st.pop();
                    if (isErase){
                        pair <char, int> top = st_oper.top();
                        if(top.first == '+'){
                            st_oper.pop();
                            int value = top.second * 2;
                            while(1){
                                if(st_oper.empty())
                                    break;
                                top = st_oper.top();
                                if(top.first == '+'){
                                    st_oper.pop();
                                    value += top.second;
                                }
                                else
                                    break;
                            }
                            st_oper.push(make_pair('+',value));
                        }
                        cout << s[i] <<" *2 ";
                    }
                    else{
                        st_oper.push(make_pair('+',2));
                        cout << s[i] << " +2 ";
                    }
                    isErase = 1;
                }
                else if(s[i] == '('){
                    st.push(s[i]);
                    isErase = 0;
                }
                else if(s[i] == '['){
                    st.push(s[i]);
                    isErase = 0;
                }
                else{
                    isWrong = 1;
                    cout << "0"<<endl;
                    break;
                }
            }
            else if(st.top() == '['){
                if(s[i] == ']'){
                    st.pop();
                    if (isErase){
                        pair <char, int> top = st_oper.top();
                        if(top.first == '+'){
                            st_oper.pop();
                            int value = top.second * 3;
                            while(1){
                                if(st_oper.empty())
                                    break;
                                top = st_oper.top();
                                if(top.first == '+'){
                                    st_oper.pop();
                                    value += top.second;
                                }
                                else
                                    break;
                            }
                            st_oper.push(make_pair('+',value));
                        }
                        cout << s[i] << " *3 ";
                    }
                    else{
                        st_oper.push(make_pair('+',3));
                        cout << s[i] << " +3 ";
                    }
                    isErase = 1;
                }
                else if(s[i] == '('){
                    st.push(s[i]);
                    isErase = 0;
                }
                else if(s[i] == '['){
                    st.push(s[i]);
                    isErase = 0;
                }
                else{
                    isWrong = 1;
                    break;
                }
            }
        }
    }
    while(1){
        if(st_oper.empty())
            break;
        pair <char, int> p = st_oper.top();
        if(p.first == '+'){
            score += p.second;
            cout << "score "<< score <<endl;
        }
        st_oper.pop();
        cout << p.first << " "<<p.second << endl;
    }
    if(!st.empty()||isWrong)
        cout << "0" << endl;
    else
        cout << score <<endl;   
}