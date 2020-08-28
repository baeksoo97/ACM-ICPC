#include <stdio.h>
#define R 10007
int main(void) {
	int n, idx[10] = { 1, }, answer;
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		answer = 0;
		int sum = 0;
		for (int j = 0; j < 10; j++) {
			sum += (idx[j] % R);
			idx[j] = (sum % R);
			answer += (sum * (10 - j));
			answer %= R;
		}	
	}
	
	printf("%d\n", n == 1 ? 10 : answer % R);
	
	return 0;
}