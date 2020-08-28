#include <iostream>
using namespace std;

int main(void) {
	long long n;
	cin >> n;
	
	long long dp[100];
	dp[1] = 1, dp[2] = 1;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;

	return 0;
}