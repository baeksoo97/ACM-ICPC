#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int n;
	vector <int> v;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (!v.size() || v.back() < a) {
			v.push_back(a);
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), a) - v.begin();
			v[it] = a;
		}
	}

	printf("%d", v.size());

	return 0;
}