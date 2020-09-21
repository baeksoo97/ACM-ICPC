#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool comp(const pair<float, int>& a, const pair<float, int>& b) {
    if (a.first > b.first) {
        return true;
    }
    else if (a.first == b.first) {
        if (a.second < b.second) return true;
        else return false;
    }
    else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> info;
    sort(stages.begin(), stages.end());

    int total = stages.size();
    for (int i = 1; i <= N + 1; i++) {
        int l_pos = lower_bound(stages.begin(), stages.end(), i) - stages.begin();
        int r_pos = upper_bound(stages.begin(), stages.end(), i) - stages.begin();
        int num_unclear = r_pos - l_pos;
        int num_reached = total - l_pos;
         
        if (i != N + 1) {
            float failure = num_reached == 0 ? 0 : (float)num_unclear / num_reached;
            info.push_back({ failure, i });
        }
    }
    sort(info.begin(), info.end(), comp);

    for (auto i : info) {
        answer.push_back(i.second);
    }
    
    return answer;
}

int main(void) {
    solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
}