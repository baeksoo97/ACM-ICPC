#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> answer_set;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int sum = numbers[i] + numbers[j];
            answer_set.insert(sum);
        }
    }

    for (auto a : answer_set) {
        answer.push_back(a);
    }

    sort(answer.begin(), answer.end());

    return answer;
}