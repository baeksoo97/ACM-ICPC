#include <iostream>
using namespace std;
#define MAX 1000001
typedef long long int ll;
int n;
int participant[MAX];
int first_cap;
int second_cap;

ll total = 0;

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &participant[i]);
	}
	scanf("%d %d", &first_cap, &second_cap);

	for (int i = 0; i < n; i++) {
		ll remain = (ll)participant[i] - (ll)first_cap;
		total++;
		//printf("%d : total %lld remain %lld \n", i, total, remain);

		if (remain >= 0) {
			ll second_need = remain / second_cap;

			if (remain % second_cap > 0) {
				second_need++;
			}
			total += second_need;

			//printf("%d : total %lld second_need %lld\n", i, total, second_need);
		}
	}
	printf("%lld\n", total);
}