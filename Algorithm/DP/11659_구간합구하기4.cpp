#include <iostream>
using namespace std;
int n, m;
int sum[100001];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
	}
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", sum[b] - sum[a - 1]);
	}
}