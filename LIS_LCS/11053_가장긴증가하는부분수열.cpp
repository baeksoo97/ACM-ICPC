#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int n, arr[1001];
	vector <int> v;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		if (!v.size() || arr[i] > v.back()) {
			v.push_back(arr[i]);
		}
		else {
			v[lower_bound(v.begin(), v.end(), arr[i]) - v.begin()] = arr[i];
		}
		
	}
	
	cout << v.size() << endl;

	return 0;
}