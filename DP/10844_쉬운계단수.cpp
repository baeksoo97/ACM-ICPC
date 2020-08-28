#include <stdio.h>
#include <string.h>
#define R 1000000000
int main(void) {
	int n, answer = 0;
	scanf("%d", &n);

	int prev[10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int curr[10] = { 0, };
	for (int i = 2; i <= n; i++) {
		memset(curr, 0, sizeof(curr));
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0)
				curr[j] += prev[j - 1];
			if (j + 1 < 10)
				curr[j] += prev[j + 1];
			curr[j] %= R;
		}
		memcpy(prev, curr, sizeof(curr));
	}

	for (int i = 0; i < 10; i++) {
		answer += curr[i];
		answer %= R;
	}
	printf("%d\n", n == 1 ? 9 : answer % R);
	return 0;
}