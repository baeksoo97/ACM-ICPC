#include <stdio.h>
#define SIZE 21
#define COMMAND 1001
#define DICE 7
int n, m, x, y, k;
int map[SIZE][SIZE];
int command[COMMAND]; // 0 right, 1 left, 2 up, 3 down

struct pos {
	int x, y;

	pos operator+(pos second) {
		pos ret;
		ret = { x + second.x, y + second.y };
		return ret;
	}

	void print() {
		printf("%d %d\n", x, y);
	}
};

const pos direction[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

struct dice {
	int top, back, right, left, front, bottom;
	int num[DICE] = { 0, }; // 1 ~ 6

	void init() {
		top = 1;
		back = 2;
		right = 3;
		left = 4;
		front = 5;
		bottom = 6; 
	}

	void rotateDown() {
		// left, right doesn't move
		int tmp = front;
		front = top;
		top = back;
		back = bottom;
		bottom = tmp;
	}

	void rotateUp() {
		int tmp = front;
		front = bottom;
		bottom = back;
		back = top;
		top = tmp;
	}

	void rotateRight() {
		int tmp = top;
		top = left;
		left = bottom;
		bottom = right;
		right = tmp;
	}

	void rotateLeft() {
		int tmp = top;
		top = right;
		right = bottom;
		bottom = left;
		left = tmp;
	}
};

class Play {
public:
	pos curr;
	dice dice;

	Play(pos dice_pos) {
		curr = dice_pos;
		dice.init();
	}

	void printMap() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
	}
	
	void rotateDice(int dir) {
		// 0 right, 1 left, 2 up, 3 down
		if (dir == 0) dice.rotateRight();
		else if (dir == 1) dice.rotateLeft();
		else if (dir == 2) dice.rotateUp();
		else if (dir == 3) dice.rotateDown();
		//printf("bottom %d\n", dice.bottom);
	}

	void updateBottomNum(pos next) {
		int map_num = map[next.x][next.y];
		
		if (map_num != 0) {
			dice.num[dice.bottom] = map_num;
			map[next.x][next.y] = 0;
		}
		else {
			map[next.x][next.y] = dice.num[dice.bottom];
		}
		//printf("dice bottom %d\n", dice.num[dice.bottom]);
	}

	void move(int step, int dir) {
		pos next = curr + direction[dir];
		if (!(next.x >= 0 && next.x < n && next.y >= 0 && next.y < m)) {
			// out of map
			return;
		}
		
		rotateDice(dir);

		//next.print();
		updateBottomNum(next);
		printf("%d\n", dice.num[dice.top]);
		//printMap();
		curr = next;
	}

	void start() {
		updateBottomNum(curr);
		for (int i = 0; i < k; i++) {
			int dir = command[i];
			move(i, dir);
		}
	}
};

int main(void) {
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &x, &y, &k);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int dir;
		scanf("%d", &dir);
		command[i] = dir - 1;
	}

	Play play({ x, y });
	play.start();
}