#include <iostream>
using namespace std;
#define LEFT 6
#define RIGHT 2
#define NUM_GEAR 4 + 1
#define NUM_STATES 8
#define MAX_ROTATE 100
#define CLOCK_WISE 1
#define UNCLOCK_WISE -1
struct Gear {
	int states[NUM_STATES]; // 0 : N, 1 : S
};

struct Rotation {
	int gear_num;
	int direction; // 1: clock-wise, -1 : unclock-wise
};

Gear gears[NUM_GEAR];
Rotation rotation[MAX_ROTATE];
int k;

class Game {
public:
	void rotate_leftside(int curr_gear, int direction) {
		int left_gear = curr_gear - 1;
		if (left_gear > 0
			&& gears[left_gear].states[RIGHT]
			!= gears[curr_gear].states[LEFT]) {
			rotate_leftside(left_gear, direction * -1);
			changeStates(left_gear, direction * -1);
		}
	}

	void rotate_rightside(int curr_gear, int direction) {
		int right_gear = curr_gear + 1;
		if (right_gear < NUM_GEAR
			&& gears[curr_gear].states[RIGHT]
			!= gears[right_gear].states[LEFT]) {
			rotate_rightside(right_gear, direction * -1);
			changeStates(right_gear, direction * -1);
		}
	}

	void changeStates(int curr_gear, int direction) {
		if (direction == CLOCK_WISE) {
			int tmp = gears[curr_gear].states[7];
			for (int i = 7; i > 0; i--) {
				gears[curr_gear].states[i] = gears[curr_gear].states[i - 1];
			}
			gears[curr_gear].states[0] = tmp;
		}
		else if (direction == UNCLOCK_WISE) {
			int tmp = gears[curr_gear].states[0];
			for (int i = 0; i < NUM_STATES - 1; i++) {
				gears[curr_gear].states[i] = gears[curr_gear].states[i + 1];
			}
			gears[curr_gear].states[7] = tmp;
		}
	}

	void rotate(int curr_gear, int direction) {
		rotate_leftside(curr_gear, direction);
		rotate_rightside(curr_gear, direction);

		changeStates(curr_gear, direction);
	}

	void start() {
		for (int i = 0; i < k; i++) {
			rotate(rotation[i].gear_num, rotation[i].direction);
		}

		int answer = 0;
		if (gears[1].states[0]) answer += 1;
		if (gears[2].states[0]) answer += 2;
		if (gears[3].states[0]) answer += 4;
		if (gears[4].states[0]) answer += 8;
		
		cout << answer << endl;
	}
};

int main(void) {
	for (int i = 1; i < NUM_GEAR; i++) {
		for (int j = 0; j < NUM_STATES; j++) {
			char c;
			cin >> c;
			gears[i].states[j] = c - '0';
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> rotation[i].gear_num >> rotation[i].direction;
	}

	Game game;
	game.start();
	return 0;
}