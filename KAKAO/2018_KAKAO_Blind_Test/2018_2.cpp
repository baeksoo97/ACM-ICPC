#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

bool checkAlphabet(char c){
    if ((c - 'a') >= 0 && (c - 'a') < 26) return true;
    else return false;
}

map<string, int> getMultipleSet(string str){
    map <string, int> multi_set;
    for(int i = 0; i < str.length() - 1; i++){
        if (!(checkAlphabet(str[i]) && checkAlphabet(str[i+1]))) continue;

        string multi = str.substr(i, 2);
        if (multi_set.count(multi)){
            multi_set[multi]++;
        }
        else{
            multi_set[multi] = 1;
        }
    }

    return multi_set;
}

int getJaccard(map<string, int> map1, map<string, int> map2){
    int num_inter = 0, num_union = 0;

    for(auto m1 : map1){
        string str1 = m1.first;

        if (map2.count(str1)){
            num_inter += min(map1[str1], map2[str1]);
            num_union += max(map1[str1], map2[str1]);
            map2.erase(str1);
        }
        else{
            num_union += map1[str1];
        }
    }

    for(auto m2 : map2){
        num_union += m2.second;
    }

    if (num_union == 0) return 65536;
    else return (num_inter * 65536 /num_union);
}

int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    map <string, int> multi_set1 = getMultipleSet(str1);
    map <string, int> multi_set2 = getMultipleSet(str2);

    answer = getJaccard(multi_set1, multi_set2);
    printf("%d\n", answer);

    return answer;
}

int main(void){
    solution("FRANCE", "french");
    solution("handshake", "shake hands");
    solution("aa1+aa2", "AAAA12");
    solution("E=M*C^2", "e=m*c^2");
    return 0;
}