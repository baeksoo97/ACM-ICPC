#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;

    vector<int> min_first(a.size());
    vector<int> min_second(a.size());

    int Min = 1000000000;
    for (int i = 0; i < a.size(); i++) {
        Min = min(a[i], Min);
        min_first[i] = Min;
    }

    Min = 1000000000;
    for (int i = a.size() - 1; i >= 0; i--) {
        Min = min(a[i], Min);
        min_second[i] = Min;
    }

    set<int> last_num;
    for (int d = 0; d < a.size() - 1; d++) {
        int first = min_first[d];
        int second = min_second[d + 1];
        int m = max(first, second);
        last_num.insert(m);
    }

    last_num.insert(min_second[0]);

    answer = last_num.size();

    return answer;
}