#include <stdio.h>
#define R 10007
int  main(void) {
	int n;
	int dp[1001] = { 0, };
	scanf("%d", &n);
	
	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] += (dp[i - 2] * 2);
		dp[i] %= R;
	}

	printf("%d\n", dp[n] % R);

	return 0;
}