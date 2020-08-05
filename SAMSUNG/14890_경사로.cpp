#include <iostream>
using namespace std;
#define MAX_SIZE 101
struct pos {
	int x, y;
	pos operator+(pos second) {
		return { x + second.x, y + second.y };
	}
};

int N, L;
int board[MAX_SIZE][MAX_SIZE];

int getDiff(pos curr, pos next) {
	int a = board[curr.x][curr.y];
	int b = board[next.x][next.y];
	return a - b;
}

bool goThrough(pos dir, pos start) {
	pos curr = start;
	pos next = start;
	int num_slope = 0;
	int num_same = 1;

	for (int i = 0; i < N - 1; i++) {
		next = next + dir;
		int diff = getDiff(curr, next);
		if (diff == 0 && num_slope % L == 0) {
			num_same++;
			curr = next;
			continue;
		}
		else if (diff == 1) {
			num_slope++;
			if (num_slope % L == 0) {
				curr = next;
				num_same = 0; // avoid duplicate slope
			}
			continue;
		}
		else if (diff == -1) {
			if (num_same >= L) {
				curr = next;
				num_same = 1;
				continue;
			}
			else return false;
		}
		else { // diff is not 0, -1, 1
			return false;
		}
	}

	// in case of [3, 2, 2, 1]
	if (num_slope % L != 0)
		return false;

	return true;
}
void solve() {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += goThrough({ 1, 0 }, { 0, i }); // go down
		answer += goThrough({ 0, 1 }, { i, 0 }); // go right
	}
	cout << answer << endl;
}

int main(void) {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	solve();
	return 0;
}