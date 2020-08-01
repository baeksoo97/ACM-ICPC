#include <iostream>
using namespace std;
#define MAX_SIZE 51
struct Pos {
	int x, y;
	
	Pos operator+(Pos second) {
		return { x + second.x, y + second.y };
	}

	Pos operator-(Pos second) {
		return { x - second.x, y - second.y };
	}
};

int n, m;
int map[MAX_SIZE][MAX_SIZE];
Pos direction[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void* memcopy(void* dest, const void* src, size_t count) {
	for (size_t i = 0; i < count; i++) {
		*((char*)dest + i) = *((char*)src + i);
	}
	return dest;
}

class Robot {
private:
	Pos robot_pos;
	int robot_dir;
	int visit[MAX_SIZE][MAX_SIZE] = { 0, };
	int num_cleaning = 0;

public:
	Robot(Pos pos, int dir_idx) {
		robot_pos = pos;
		robot_dir = dir_idx;
		memcopy(visit, map, sizeof(map));
	}
	
	int rotate(int dir) {
		if (dir == 0) return 3;
		else return dir - 1;
	}

	bool isOutofRange(Pos pos) {
		if (pos.x >= 0 && pos.x < n && pos.y >= 0 && pos.y < m)
			return false;
		else
			return true;
	}

	void proceed(Pos curr, int dir) {
		// first, clean
		if (!map[curr.x][curr.y]){
			map[curr.x][curr.y] = 2; // cleaned
			visit[curr.x][curr.y] = 1;
			num_cleaning++;
		}

		// second, search
		int curr_dir = dir;
		Pos next_pos;
		int next_dir;
		int cnt = 0; 
		for (int i = 0; i < 4; i++) {
			next_dir = rotate(curr_dir);
			next_pos = curr + direction[next_dir];
			
			// next is a place to clean and not a wall
			if (!isOutofRange(next_pos)
				&& !map[next_pos.x][next_pos.y]
				&& !visit[next_pos.x][next_pos.y]) {
				break;
			}
			// next is already cleaned or a wall 
			else {
				cnt++;
				curr_dir = next_dir;
				continue;
			}
		}
		
		if (cnt == 4) {
			Pos back_pos = curr - direction[curr_dir];
			if (isOutofRange(back_pos) || map[back_pos.x][back_pos.y] == 1)
				return;
			else
				proceed(back_pos, curr_dir);
		}
		else {
			proceed(next_pos, next_dir);
		}

		return;
	}

	void start() {
		proceed(robot_pos, robot_dir);
		cout << num_cleaning << endl;
	}
};

int main(void) {
	Pos pos;
	int dir_idx;
	
	cin >> n >> m;
	cin >> pos.x >> pos.y >> dir_idx;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	Robot robot(pos, dir_idx);
	robot.start();
	return 0;
}