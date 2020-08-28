#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(string s) {
    int len = s.length();
    int answer = len;
    for (int num = 1; num <= len; num++) {
        int idx = 0, sum = 0;
        string compact = "";
        string curr = s.substr(idx, num);
        while (true) {
            idx += num;
            string next = s.substr(idx, num);
            
            if (!curr.compare(next)) {
                sum++;
            }
            else {
                if (sum == 0) {
                    compact += curr;
                }
                else {
                    compact += to_string(sum + 1);
                    compact += curr;

                }
                sum = 0;
            }

            if (idx + num > len) {
                compact += next;
                break;
            }
            curr = next;
        }

        if (answer > compact.length())
            answer = compact.length();
    }
    return answer;
}

int main(void) {
    string s[5] = { "aabbacc", "ababcdcdababcdcd", "abcabcdede", "abcabcabcabcdededededede", "xababcdcdababcdcd" };
    /*for (int i = 0; i <5; i++) {
        cout << s[i] << endl;
        solution(s[i]);
        cout << endl;
    }*/
    string s2 = "aaaaaaaaaabb";
    solution(s2);
}