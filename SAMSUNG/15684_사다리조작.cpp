#include <iostream>
using namespace std;
#define MAX_LINE_NUM 12
#define MAX_ROAD_NUM 31
#define MAX_ANSWER 4
#define MAX 99999999
int N, M, H;
int info[MAX_LINE_NUM][MAX_ROAD_NUM];

class Program {
private:
	int answer = MAX;
	int end_line[MAX_LINE_NUM] = { 0, };
public:
	int goDown(int line_num, int road_num) {
		int cnt = 0;
		for (int i = road_num; i <= H; i++) {
			if (info[line_num - 1][i]) {
				return goDown(line_num - 1, i + 1);
			}
			else if (info[line_num][i]) {
				return goDown(line_num + 1, i + 1);
			}
			cnt++;
		}

		if (cnt == H - road_num + 1) {
			return line_num;
		}
	}

	bool isCorrect() {
		for (int i = 1; i <= N; i++) {
			end_line[i] = goDown(i, 1);
		}

		for (int i = 1; i <= N; i++) {
			if (end_line[i] != i)
				return false;
		}

		return true;
	}

	void dfs(int max, int cnt, int prev_line) {
		if (cnt == max) {
			if (isCorrect()) {
				if (answer > max) answer = max;
			}
			return;
		}

		for (int i = prev_line; i <= N; i++) {
			for (int j = 1; j <= H; j++) {
				if (!info[i][j] && !info[i + 1][j] && !info[i - 1][j]) {
					info[i][j] = 1;
					dfs(max, cnt + 1, i);
					info[i][j] = 0;
				}
			}
		}
	}

	void solve() {
		for (int i = 0; i < 4; i++) {
			dfs(i, 0, 1);
		}
		if (answer == MAX)
			cout << -1 << endl;
		else
			cout << answer << endl;
	}
};

int main(void) {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		info[b][a] = 1;
	}
	Program program;
	program.solve();

	return 0;
}