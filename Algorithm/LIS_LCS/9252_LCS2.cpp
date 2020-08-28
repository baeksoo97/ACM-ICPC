#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.size(), m = s2.size();
	vector <vector<int>> v(n + 1, vector<int>(m + 1, 0));
	vector <vector<int>> dir(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				v[i][j] = v[i - 1][j - 1] + 1;
				dir[i][j] = 0;
			}
			else {
				if (v[i][j - 1] >= v[i - 1][j]) {
					v[i][j] = v[i][j - 1];
					dir[i][j] = -1;
				}
				else {
					v[i][j] = v[i - 1][j];
					dir[i][j] = 1;
				}
			}
		}
	}

	vector <char> answer;
	int i = n, j = m;
	while (i != 0 && j != 0) {
		if (dir[i][j] == 0) answer.push_back(s1[i - 1]);
		if (dir[i][j] == 0) i--, j--;
		else if (dir[i][j] == 1) i--;
		else if (dir[i][j] == -1) j--;
	}

	cout << v[n][m] << endl;
	reverse(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}

	return 0;
}