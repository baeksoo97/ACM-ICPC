#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 21
#define MAX 99999999
typedef pair<int, pair<int, int>> pii;
struct Pos {
	int x, y;
	Pos operator+(Pos second) {
		return { x + second.x, y + second.y };
	}
};
struct Info {
	int dist;
	Pos pos;
};


template<class T> class Priority_Queue {
private:
	int front_idx;
	int last_idx;
	int _size;
	T* values;
public:
	Priority_Queue() {
		_size = MAX_SIZE * MAX_SIZE;
		values = new T[_size];

		front_idx = 0;
		last_idx = -1;
	}

	~Priority_Queue() {
		delete[] values;
	}

	void push(T value) {
		if (!isFull()) values[++last_idx] = value;
		else printf("queue is full\n");
	}

	void pop() {
		if (!empty()) front_idx++;
		else printf("queue is empty\n");
	}

	T front() {
		if (!empty()) return values[front_idx];
	}

	bool empty() {
		if (front_idx > last_idx) return true;
		else return false;
	}

	bool isFull() {
		if (last_idx == _size) return true;
		else return false;
	}
};

Pos dir[4] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };
int N;
int board[MAX_SIZE][MAX_SIZE];
Pos shark_pos;
int shark_size = 2;
int answer = 0;
int eaten_num = 0;

bool isOutOfRange(Pos curr) {
	if (curr.x >= 0 && curr.x < N && curr.y >= 0 && curr.y < N) return false;
	return true;
}

Pos getMostTopLeftPos(Pos a, Pos b) {
	if (a.x < b.x) return a;
	else if (a.x == b.x) return a.y <= b.y ? a : b;
	else return b;
}

Info getNearFish(Pos start) {
	bool visit[MAX_SIZE][MAX_SIZE] = { false, };

	priority_queue <pii, vector<pii>, greater<pii>> q;
	q.push({ 0, {start.x, start.y} });
	visit[start.x][start.y] = true;

	Info fish = { MAX, {N, N} };

	while (!q.empty()) {
		int curr_dist = q.top().first;
		Pos curr = { q.top().second.first, q.top().second.second };
		q.pop();
		
		if (board[curr.x][curr.y] && board[curr.x][curr.y] < shark_size) {
			if (fish.dist >= curr_dist) {
				fish.dist = curr_dist;
				fish.pos = getMostTopLeftPos(fish.pos, curr);
			}
		}

		for (int d = 0; d < 4; d++) {
			Pos next = curr + dir[d];
			if (isOutOfRange(next)) continue;
			if (!visit[next.x][next.y] && board[next.x][next.y] <= shark_size) {
				q.push({ curr_dist + 1, {next.x, next.y} });
				visit[next.x][next.y] = true;
			}
		}
	}
	
	return fish;
}

void solve() {
	Info fish = getNearFish(shark_pos);
	//printf("fish %d : %d, %d\n", fish.dist, fish.pos.x, fish.pos.y);

	if (fish.dist == MAX) {
		//nothing to eat;
		cout << answer << endl;
		return;
	}

	board[fish.pos.x][fish.pos.y] = 0;
	answer += fish.dist;
	shark_pos = fish.pos;

	if (shark_size == ++eaten_num) {
		shark_size++;
		eaten_num = 0;
	}
	//printf("shark_size %d , eaten_num %d, answer %d\n", shark_size, eaten_num, answer);
	solve();
	return;	
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark_pos = { i, j };
				board[i][j] = 0;
			}
		}
	}
	solve();

	return 0;
}