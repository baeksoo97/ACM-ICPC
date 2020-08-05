#include <iostream>
using namespace std;
#define MAX_TIMES 1000
#define CLOCKWISE '+'
#define UNCLOCKWISE '-'

int idxRotateMain[2][9] = {
	{6, 3, 0, 7, 4, 1, 8, 5, 2},
	{2, 5, 8, 1, 4, 7, 0, 3, 6}
};
int idxRotateSide[6][4] = {
	{3, 5, 2, 4}, {2, 5, 3, 4}, {0, 5, 1, 4},
	{0, 4, 1, 5}, {0, 2, 1, 3}, {0, 3, 1, 2}
};
int idxSide[6][4][3] = {
	// Up, Right, Down, Left
	{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}},
	{{6, 7, 8}, {6, 7, 8}, {6, 7, 8}, {6, 7, 8}},
	{{6, 7, 8}, {0, 3, 6}, {2, 1, 0}, {8, 5, 2}},
	{{2, 1, 0}, {0, 3, 6}, {6, 7, 8}, {8, 5, 2}},
	{{0, 3, 6}, {0, 3, 6}, {0, 3, 6}, {8, 5, 2}},
	{{8, 5, 2}, {0, 3, 6}, {8, 5, 2}, {8, 5, 2}}
};

int test, N;
char origin_cube[6][10] = { // U, D, F, B, L, R
	"wwwwwwwww", "yyyyyyyyy", "rrrrrrrrr",
	"ooooooooo", "ggggggggg", "bbbbbbbbb"
};
char cube[6][10];

void* memcopy(void* dest, void* src, size_t cnt);
int getIdx(char side);
void changeMain(int main, int dir);
void changeSide(int main, int dir);
void rotateCube(int main, int dir);

int main(void) {
	cin >> test;
	while (test--) {
		cin >> N;
		memcopy(cube, origin_cube, sizeof(origin_cube));
		for (int i = 0; i < N; i++) {
			char side, dir;
			cin >> side >> dir;
			int d = (dir == CLOCKWISE) ? 0 : 1;
			rotateCube(getIdx(side), d);
		}
		for (int i = 0; i < 9; i++) {
			cout << cube[0][i];
			if (i % 3 == 2)
				cout << endl;
		}
	}
	return 0;
}

void* memcopy(void* dest, void* src, size_t cnt) {
	for (size_t i = 0; i < cnt; i++) {
		*((char*)dest + i) = *((char*)src + i);
	}
	return dest;
}

int getIdx(char side) {
	switch (side) {
	case 'U': return 0;
	case 'D': return 1;
	case 'F': return 2;
	case 'B': return 3;
	case 'L': return 4;
	case 'R': return 5;
	}
}

void changeMain(int main, int dir) {
	char tmp[10];
	for (int i = 0; i < 9; i++) {
		tmp[i] = cube[main][idxRotateMain[dir][i]];
	}

	memcopy(cube[main], tmp, sizeof(tmp));
}

void changeSide(int main, int dir) {
	if (dir == 0) {
		int last = idxRotateSide[main][3];
		char tmp[10];
		memcopy(tmp, cube[last], sizeof(cube[last]));
		// Up, Right, Down, Left
		for (int i = 3; i > 0; i--) {
			int prev_side = idxRotateSide[main][i - 1];
			int side = idxRotateSide[main][i];
			for (int j = 0; j < 3; j++) {
				cube[side][idxSide[main][i][j]] = cube[prev_side][idxSide[main][i - 1][j]];
			}
		}
		int first = idxRotateSide[main][0];
		for (int j = 0; j < 3; j++) {
			cube[first][idxSide[main][0][j]] = tmp[idxSide[main][3][j]];
		}
	}
	else if (dir == 1) {
		int first = idxRotateSide[main][0];
		char tmp[10];
		memcopy(tmp, cube[first], sizeof(cube[first]));
		for (int i = 0; i < 3; i++) {
			int prev_side = idxRotateSide[main][i + 1];
			int side = idxRotateSide[main][i];
			for (int j = 0; j < 3; j++) {
				cube[side][idxSide[main][i][j]] = cube[prev_side][idxSide[main][i + 1][j]];
			}
		}
		int last = idxRotateSide[main][3];
		for (int j = 0; j < 3; j++) {
			cube[last][idxSide[main][3][j]] = tmp[idxSide[main][0][j]];
		}
	}
}

void rotateCube(int main, int dir) {
	changeMain(main, dir);
	changeSide(main, dir);
}
