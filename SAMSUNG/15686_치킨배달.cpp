#include <iostream>
using namespace std;
#define MAX_SIZE 51
#define MAX_CHICKEN 14
#define MAX_DIST 1000
struct pos {
	int x, y;
	pos operator+(pos second) {
		return { x + second.x, y + second.y };
	}
};

int N, M;
int map[MAX_SIZE][MAX_SIZE];

class Program {
private:
	pos newStores[MAX_CHICKEN];
	int answer = 999999999;
public:
	pos houses[MAX_SIZE * 2];
	pos stores[MAX_CHICKEN];
	int num_houses = 0;
	int num_stores = 0;

	int getDistance(pos house, pos store) {
		int d_x = house.x - store.x;
		int d_y = house.y - store.y;
		d_x = d_x < 0 ? -d_x : d_x;
		d_y = d_y < 0 ? -d_y : d_y;
		return d_x + d_y;
	}

	void updateDistance() {
		int totalDist = 0;
		for (int i = 0; i < num_houses; i++) {
			int minDist = MAX_DIST;
			for (int j = 0; j < M; j++) {
				int dist = getDistance(houses[i], newStores[j]);
				if (minDist > dist) minDist = dist;
			}
			totalDist += minDist;
		}
		if (totalDist < answer) answer = totalDist;
	}

	void dfs(int cnt, int prev) {
		if (cnt == M) {
			updateDistance();
			return;
		}

		for (int i = prev; i < num_stores; i++) {
			newStores[cnt] = stores[i];
			dfs(cnt + 1, i + 1);
		}
	}

	void solve() {
		dfs(0, 0);
		cout << answer << endl;
	}
};

int main(void) {
	cin >> N >> M;
	Program program;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				program.houses[program.num_houses++] = { i, j };
			}
			if (map[i][j] == 2) {
				program.stores[program.num_stores++] = { i, j };
			}
		}
	}

	program.solve();
	return 0;
}