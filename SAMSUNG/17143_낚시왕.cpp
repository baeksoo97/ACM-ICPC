#include <iostream>
using namespace std;
#define MAX_SIZE 101
#define MAX_NUM 10001
struct Pos {
	int x, y;
	Pos operator+(Pos second) {
		return { x + second.x, y + second.y };
	}
	Pos operator*(int num) {
		return { x * num, y * num };
	}
	Pos getRightPos(int num) {
		if (x < 0 && y == 0) return { x + num, 0 };
		else if (y < 0 && x == 0) return { 0, y + num };
		else return { x, y };
	}
};
struct Shark {
	Pos pos;
	int speed;
	int dir;
	int size;
	bool isDead = false;
};

Pos direction[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
Shark shark[MAX_NUM];
int board[MAX_SIZE][MAX_SIZE];
int R, C, M;
int answer = 0;

void* memcpy(void* dest, void* src, size_t count) {
	for (size_t i = 0; i < count; i++) {
		*((char*)dest + i) = *((char*)src + i);
	}
	return dest;
}

int getOppositeDir(int dir) {
	return (dir % 2) ? dir + 1 : dir - 1;
}

void moveShark() {
	int tmp[MAX_SIZE][MAX_SIZE] = { 0, };
	for (int i = 1; i <= M; i++) {
		if (shark[i].isDead) continue;

		int dir = shark[i].dir;
		int dist = shark[i].speed;
		int length = (dir / 3) ? C - 1 : R - 1;
		int unfix_pos = (dir / 3) ? shark[i].pos.y : shark[i].pos.x;
		
		// right, down 
		if (dir == 2 || dir == 3) dist -= (length - unfix_pos + 2);
		else dist -= unfix_pos;
		
		if (dist >= 0) {
			int freq = dist / length;
			int idx = dist % length;
			if (freq % 2 == 0) dir = getOppositeDir(dir);

			Pos move = direction[dir] * (idx + 2);
			if (dir / 3) shark[i].pos.y = move.getRightPos(length + 2).y;
		    else shark[i].pos.x = move.getRightPos(length + 2).x;
			shark[i].dir = dir;
		}
		else {
			Pos move = direction[dir] * shark[i].speed;
			if (dir / 3) shark[i].pos.y += move.y;
			else shark[i].pos.x += move.x;
		}

		int prev_shark = tmp[shark[i].pos.x][shark[i].pos.y];
		if (!prev_shark){
			tmp[shark[i].pos.x][shark[i].pos.y] = i;
		}
		else if (shark[prev_shark].size < shark[i].size) {
			tmp[shark[i].pos.x][shark[i].pos.y] = i;
			shark[prev_shark].isDead = true;
		}
		else {
			shark[i].isDead = true;
		}
	}

	memcpy(board, tmp, sizeof(tmp));
}

void getShark(int fishman) {
	for (int i = 1; i <= R; i++) {
		int shark_idx = board[i][fishman];
		if (shark_idx) {
			board[i][fishman] = 0;
			shark[shark_idx].isDead = true;
			answer += shark[shark_idx].size;
			break;
		}
	}
}

void solve() {
	for (int i = 1; i <= C; i++) {
		getShark(i);
		moveShark();
	}
	cout << answer << endl;
}


int main(void) {
	cin >> R >> C >> M;
	
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].pos.x >> shark[i].pos.y;
		cin >> shark[i].speed >> shark[i].dir >> shark[i].size;
		board[shark[i].pos.x][shark[i].pos.y] = i;
	}

	solve();

	return 0;
}

