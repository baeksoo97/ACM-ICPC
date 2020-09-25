#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPass(vector<int>& gaps, int gap, int k){
    int sum = 0;
    for(auto g : gaps){
        if (g > gap){
            if (g % gap == 0) sum += (g/gap) - 1;
            else sum += g/gap;
        }
    }
    if (sum <= k) return true;
    else return false;
}

int main(void){
    int test, n, k, answer, a;
    vector<int> minutes, gaps;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++){
        minutes.clear();
        gaps.clear();
        answer = 0;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            minutes.push_back(a);
            if (i != 0) gaps.push_back(minutes[i] - minutes[i-1]);
        }
        sort(gaps.begin(), gaps.end());

        int left = 1, right = gaps[gaps.size() - 1];
        int mid;
        while(left < right){
            mid = (left + right) / 2;
            if (canPass( gaps, mid, k)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        answer = right;
        printf("Case #%d: %d\n", t, answer);
    }
    return 0;
}