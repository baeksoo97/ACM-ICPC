#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[101][101][101];

int main(void) {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			for (int k = 1; k <= s3.size(); k++) {
				if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1]) {
					arr[i][j][k] = arr[i - 1][j - 1][k - 1] + 1;
				}
				else {
					arr[i][j][k] = max(arr[i - 1][j][k], arr[i][j - 1][k]);
					arr[i][j][k] = max(arr[i][j][k], arr[i][j][k - 1]);
				}
			}
		}
	}

	cout << arr[s1.size()][s2.size()][s3.size()] << endl;

	return 0;
}