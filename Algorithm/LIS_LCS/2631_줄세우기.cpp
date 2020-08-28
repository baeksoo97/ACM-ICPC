#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);
	vector <int> v;
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

	cout << n - v.size() << endl;
	return 0;
}