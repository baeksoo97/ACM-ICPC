#include <iostream>
using namespace std;
#define MAX_NUM 12
#define MAX_LL 1000000000
typedef long long ll;
int n;
ll arr[MAX_NUM];
int operations[4]; // +, -, x, /
ll min_answer = MAX_LL;
ll max_answer = -MAX_LL;

ll doOperate(int option, ll first, ll second); 
void operate(ll prev, int curr_idx); 
void start();

int main(void) {
	cin >> n;
	for (int i = 1;  i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operations[i];
	}
	start();
	return 0;
}

ll doOperate(int option, ll first, ll second) {
	if (option == 0) return first + second;
	else if (option == 1) return first - second;
	else if (option == 2) return first * second;
	else if (option == 3) return first / second;
}

void operate(ll prev, int curr_idx) {
	if (curr_idx > n) {
		if (prev < min_answer) min_answer = prev;
		if (prev > max_answer) max_answer = prev;
	}

	// +, -, x, /
	for (int i = 0; i < 4; i++) {
		ll curr = arr[curr_idx];
		if (operations[i] > 0) {
			curr = doOperate(i, prev, curr);
			operations[i]--;
			operate(curr, curr_idx + 1);
			operations[i]++;
		}
	}
}

void start() {
	int prev_idx = 1;
	operate(arr[prev_idx], prev_idx + 1);
	cout << max_answer << endl;
	cout << min_answer << endl;
}
