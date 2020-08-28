#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int divide(string w) {
    int sum = 0, i;
    bool isRight = true;
    for (i = 0; i < w.length(); i++) {
        if (w[i] == '(') sum++;
        else if (w[i] == ')') sum--;
        if (sum < 0) isRight = false;
        else if (sum == 0) break;
    }
    return i;
}

bool isRight(string s) {
    int sum = 0, i;
    for (i = 0; i < s.length(); i++) {
        if (s[i] == '(') sum++;
        else if (s[i] == ')') sum--;
        if (sum < 0) return false;
    }
    return true;
}

string play(string w) {
    if (w.length() == 0) return "";
    if (isRight(w)) return w; 

    int idx = divide(w);
    string u = w.substr(0, idx + 1);
    string v = w.substr(idx + 1, w.length() - idx + 1);

    if (isRight(u)) {
        u += play(v);
    }
    else {
        string sub = "";
        for (int i = 1; i < u.length() - 1; i++) {
            if (u[i] == ')') sub += '(';
            else if (u[i] == '(') sub += ')';
        }

        u = ("(" + play(v) + ")" + sub);
    }
    return u;
}


string solution(string p) {
    string answer = "";

    answer = play(p);
    cout << answer << endl;
    return answer;
}

int main(void) {
    string p;
    cin >> p;
    solution(p);
}