#include <iostream>
using namespace std;
#define MAX_SIZE 21
#define ABS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int n;
int capacity[MAX_SIZE][MAX_SIZE];
int first_team[MAX_SIZE];
int second_team[MAX_SIZE];

class Program {
private:
	int answer = 99999999; 
public:
	void setSecondTeammate() {
		int first_idx = 1;
		int second_idx = 1;
		for (int i = 1; i <= n; i++) {
			if (i == first_team[first_idx]) {
				first_idx++;
			}
			else {
				second_team[second_idx++] = i;
			}
		}
	}

	int getDifference() {
		int sum_first = 0;
		int sum_second = 0;
		for (int i = 1; i < n / 2; i++) {
			for (int j = i + 1; j <= n / 2; j++) {
				int a = first_team[i];
				int b = first_team[j];
				int c = second_team[i];
				int d = second_team[j];
				sum_first += capacity[a][b] + capacity[b][a];
				sum_second += capacity[c][d] + capacity[d][c];
			}
		}
		
		return ABS(sum_first, sum_second);
	}

	void pickTeammate(int cnt) {
		if (cnt > n / 2) {
			setSecondTeammate();
			int diff = getDifference();
			if (answer > diff)
				answer = diff;
			return;
		}
		
		for (int i = first_team[cnt - 1] + 1; i <= n; i++) {
			first_team[cnt] = i;
			pickTeammate(cnt + 1);
		}
	}

	void solve() {
		pickTeammate(1);
		cout << answer << endl;
	}
};

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> capacity[i][j];
		}
	}
	Program program;
	program.solve();

	return 0;
}