#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	pair<int, int> arr[100];
	vector <int> v;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[i] = { a, b };
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		int second = arr[i].second;
		
		if (!v.size() || v.back() < second) {
			v.push_back(second);
		}
		else {
			v[lower_bound(v.begin(), v.end(), second) - v.begin()] = second;
		}
	}

	cout << n - v.size() << endl;

	return 0;
}