#include <iostream>
using namespace std;

#define MAX_SIZE 50
struct pos {
	int x, y;
	pos operator+(pos second) {
		return { x + second.x, y + second.y };
	}
};
pos dir[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int board[MAX_SIZE][MAX_SIZE];
int N, M, T;
int top;
int bottom;

void* memcpy(void* dest, void* src, size_t count) {
	for (size_t i = 0; i < count; i++) {
		*((char*)dest + i) = *((char*)src + i);
	}
	return dest;
}

void do_aircleaner() {
	for (int i = top - 1; i > 0; i--)
		board[i][0] = board[i - 1][0];

	for (int i = 0; i < M - 1; i++)
		board[0][i] = board[0][i + 1];

	for (int i = 0; i < top; i++)
		board[i][M - 1] = board[i + 1][M - 1];

	for (int i = M - 1; i > 1; i--)
		board[top][i] = board[top][i - 1];

	board[top][1] = 0;

	for (int i = bottom + 1; i < N - 1; i++)
		board[i][0] = board[i + 1][0];

	for (int i = 0; i < M - 1; i++)
		board[N - 1][i] = board[N - 1][i + 1];

	for (int i = N - 1; i > bottom; i--)
		board[i][M - 1] = board[i - 1][M - 1];

	for (int i = M - 1; i > 1; i--)
		board[bottom][i] = board[bottom][i - 1];

	board[bottom][1] = 0;
}

void spread_dust() {
	int tmp[MAX_SIZE][MAX_SIZE];
	memcpy(tmp, board, sizeof(board));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] < 5) continue;
			pos curr = { i, j };
			for (int d = 0; d < 4; d++) {
				pos next = curr + dir[d];
				int curr_dust = board[curr.x][curr.y] / 5;
				if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < M
					&& tmp[next.x][next.y] != -1) {
					tmp[next.x][next.y] += curr_dust;
					tmp[curr.x][curr.y] -= curr_dust;
				}
			}
		}
	}
	memcpy(board, tmp, sizeof(tmp));
}

void solve() {
	while (T--) {
		spread_dust();
		do_aircleaner();
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == -1) continue;
			answer += board[i][j];
		}
	}
	cout << answer << endl;
}

int main(void) {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1) {
				bottom = i;
			}
		}
	}
	top = bottom - 1;

	solve();
	return 0;
}