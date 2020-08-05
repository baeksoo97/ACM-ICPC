#include <iostream>
using namespace std;
#define MAX_SIZE 9
#define WALL 1

struct pos {
	int x, y;
	pos operator+(pos second) {
		return { x + second.x, y + second.y };
	}
};

pos direction[4] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

unsigned int cctv_direction[6] = {
	0, 4, 5, 12, 13, 15 
	//0x0000, 0x0100, 0x0101, 0x1100, 0x1101, 0x1111
};

int n, m;
int map[MAX_SIZE][MAX_SIZE];
pos cctv[MAX_SIZE];
int sum_cctv = 0;

class Program {
private:
	int answer = 99999999;
public:
	void* copyMap(void* dest, void* src, size_t count) {
		for (size_t i = 0; i < count; i++) {
			*((char*)dest + i) = *((char*)src + i);
		}
		return dest;
	}

	unsigned int rotateDirection(unsigned int dir) {
		unsigned int next_dir = dir >> 1;
		if (dir & (unsigned int)1) next_dir += 8;

		return next_dir;
	}
	
	void setMap(pos cctv_pos, unsigned int cctv_dir) {
		int j = 8;
		for (int i = 0; i < 4; i++) {
			// 0100
			if (cctv_dir & j) {
				pos dir = direction[i];
				pos next_pos = cctv_pos;
				while (1) {
					next_pos = next_pos + dir;
					if (next_pos.x < 0 || next_pos.x >= n
						|| next_pos.y < 0 || next_pos.y >= m
						|| map[next_pos.x][next_pos.y] == 6) {
						break;
					}
					else {
						if (map[next_pos.x][next_pos.y] == 0)
							map[next_pos.x][next_pos.y] = 7;
					}
				}
			}
			j = j / 2;
		}
	}
	
	void printMap() {
		cout << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	int getBlindSpotSize() {
		int total = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) total++;
			}
		}
		return total;
	}

	void searchCCTVRange(int cctv_idx) {
		if (cctv_idx == sum_cctv) {
			//printMap();
			int blind_size = getBlindSpotSize();
			if (answer > blind_size)
				answer = blind_size;

			return;
		}

		pos cctv_pos = cctv[cctv_idx];
		int cctv_num = map[cctv_pos.x][cctv_pos.y];
		unsigned int cctv_dir = cctv_direction[cctv_num];
		int tmpMap[MAX_SIZE][MAX_SIZE];
		for (int r = 0; r < 4; r++) {
			copyMap(tmpMap, map, sizeof(map));
			cctv_dir = rotateDirection(cctv_dir);
			setMap(cctv_pos, cctv_dir);
			searchCCTVRange(cctv_idx + 1);
			copyMap(map, tmpMap, sizeof(map));
		}
	}

	void solve() {
		searchCCTVRange(0);
		cout << answer << endl;
	}
};

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) {
				cctv[sum_cctv++] = { i, j };
			}
		}
	}
	Program program;
	program.solve();
	return 0;
}