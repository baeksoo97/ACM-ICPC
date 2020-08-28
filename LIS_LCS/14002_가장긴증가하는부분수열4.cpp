#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main(void) {
	int n, arr[1001], prev[1001];
	vector <pair<int, int>> v;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		if (!v.size()) {
			prev[i] = -1;
			v.push_back({ arr[i], i });
		}
		else if (v.back().first < arr[i]) {
			prev[i] = v.back().second;
			v.push_back({ arr[i], i });
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), pair<int, int>(arr[i], 0), comp) - v.begin();
			v[it] = { arr[i], i };
			if (it == 0) prev[i] = -1;
			else prev[i] = v[it - 1].second;
		}
	}

	vector <int> answer;
	int p = v.back().second;
	while (p >= 0) {
		answer.push_back(arr[p]);
		p = prev[p];
	}

	cout << answer.size() << endl;
	for (int i = 1; i <= answer.size(); i++) {
		cout << answer[answer.size() - i] << " ";
	}

	return 0;
}