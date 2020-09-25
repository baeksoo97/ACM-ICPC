#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int test, n, k, p, answer;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++){
        answer = 0;
        scanf("%d %d %d", &n, &k, &p);
        vector<vector<int> > dishes(n + 1, vector<int>(k + 1, 0));
        vector<vector<int> > sum(n + 1, vector<int>(k + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                scanf("%d", &dishes[i][j]);
                if (j <= k) sum[i][j] = sum[i][j - 1] + dishes[i][j];
                else sum[i][j] = sum[i][j-1];
            }
        }

        vector<vector<int> > dp(n + 1, vector<int>(p + 1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= p; j++){
                for(int x = 0; x <= min(j, k); x++){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - x] + sum[i][x]);
                }
            }
        }

        answer = dp[n][p];

        printf("Case #%d: %d\n", t, answer);
    }

    return 0;
}