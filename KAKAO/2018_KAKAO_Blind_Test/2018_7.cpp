#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    reverse(dartResult.begin(), dartResult.end());

    char square = ' ';
    char prev = ' ';
    int score = 0;
    int cnt = 0;
    vector<int> options(dartResult.size(), 1);

    for(int i = 0; i < dartResult.size(); i++){
        char c = dartResult[i];

        if (c == 'S' || c == 'D' || c == 'T'){
            square = c;
        }
        else if (c == '#' || c == '*'){
            if ( c == '#') options[cnt] *= -1;
            else {
                options[cnt] *= 2;
                options[cnt + 1] *= 2;
            }
        }
        else{
            int num;
            if (prev == '0'){
                num = 10;
            }
            else num = c - '0';

            if (square == 'D') num = num * num;
            else if (square == 'T') num = num * num * num;

            score = score + num * options[cnt];
            cnt++;
        }
        prev = c;
    }

    answer = score;

    return answer;
}

int main(void){
    solution("10T*");
}