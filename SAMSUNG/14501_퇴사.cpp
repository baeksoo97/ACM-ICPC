#include <iostream>
using namespace std;
#define MAX_SIZE 16
#define max(a, b) (a > b)? a: b
int n;
int times[MAX_SIZE];
int profit[MAX_SIZE];
int dp[MAX_SIZE];

void solve() {
    int answer = 0;

    for (int i = 1; i <= n + 1; i++) {
        int possible_max = 0;
        for (int j = 1; j <= 5; j++) {
            if (i - j > 0) {
                if (j >= times[i - j]) {
                    int possible_profit = dp[i - j] + profit[i - j];
                    if (possible_max < possible_profit) {
                        possible_max = possible_profit;
                    }
                }
            }
        }
        dp[i] = max(possible_max, dp[i - 1]);
    }
    answer = dp[n + 1];

    cout << answer << endl;
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> times[i] >> profit[i];
    }

    solve();

    return 0;
}
