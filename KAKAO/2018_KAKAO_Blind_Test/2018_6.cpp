#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, "");

    for(int i = 0; i < n; i++){
        int product = arr1[i] | arr2[i];
        printf("%d\n", product);
        for(int j = 0; j < n; j++){
            int mask = 1 << j;
            if (product & mask) answer[i].push_back('#');
            else answer[i].push_back(' ');
        }
        reverse(answer[i].begin(), answer[i].end());
    }

    return answer;
}

int main(void){
    solution(5, {9, 20, 28, 18, 11}, {30, 1, 21,17, 28});
}