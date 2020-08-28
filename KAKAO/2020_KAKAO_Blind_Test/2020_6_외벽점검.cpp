#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int answer = 999999999;
vector <int> selected;
bool choosed[10];

vector<int> rotateWeak(int n, const vector<int>& weak) {
    vector<int> new_weak(weak.size());
    for (int i = 0; i < weak.size() - 1; i++) {
        new_weak[i] = weak[i + 1];
    }
    new_weak[weak.size() - 1] = weak[0] + n;
    return new_weak;
}

bool checkCover(int n, vector<int> weak, const vector<int>& dist) {
    bool isCover = false;

    for (int i = 0; i < weak.size(); i++) {
        int curr_idx = 0;
        for (int i = 0; i < dist.size(); i++) {
            int curr_pos = weak[curr_idx];
            int next_pos = curr_pos + dist[i];
            while (curr_idx < weak.size() - 1 && next_pos >= weak[curr_idx + 1]) {
                curr_idx++;
            }
            curr_idx++;
            if (curr_idx >= weak.size()) {
                isCover = true;
                break;
            }
        }
        if (isCover) break;
        weak = rotateWeak(n, weak);
    }

    if (isCover) return true;
    else return false;
}

void dfs(int cnt, int n, vector<int> weak, vector<int> dist) {
    for (int i = 0; i < dist.size(); i++) {
        if (choosed[i]) continue;

        choosed[i] = true;
        selected.push_back(dist[i]);
        if (checkCover(n, weak, selected)) {
            answer = min(answer, cnt + 1);
        }
        dfs(cnt + 1, n, weak, dist);
        selected.pop_back();
        choosed[i] = false;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    answer = 999999999;
    memset(choosed, false, sizeof(choosed));
    dfs(0, n, weak, dist);

    if (answer == 999999999) answer = -1;
    cout << answer << endl;
    return answer;
}

int main(void) {
    solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 });
    solution(12, { 1, 3, 4, 9, 10 }, { 3, 5, 7 });
    solution(200, { 0, 10, 50, 80, 120, 160 }, { 1, 10, 5, 40, 30 });
    solution(30, { 0, 3, 11, 21 }, { 10, 4 });
    solution(50, { 1 }, { 1, 2, 3, 4, 5,6 });
}