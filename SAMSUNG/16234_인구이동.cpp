#include <iostream>
using namespace std;
#define MAX_SIZE 50
#define DIFF(a, b) ((a)>(b) ? (a)-(b) : (b)-(a))

struct pos {
	int x, y;
	pos operator+(pos second) {
		return { x + second.x, y + second.y };
	}
};

template<class T> class Queue {
private:
	T* values;
	int _size;
	int front;
	int rear;
	int total;
public:
	Queue() {
		_size = MAX_SIZE * MAX_SIZE;
		values = new T[_size];
		front = 0;
		rear = -1;
		total = 0;
	}
	~Queue() {
		delete[] values;
	}

	T top() {
		if (!empty()) return values[front];
	}

	void push(T element) {
		if (isFull()) cout << "queue is full\n";
		else {
			rear = (rear + 1) % _size;
			values[rear] = element;
			total++;
		}
	}

	void pop() {
		if (empty()) cout << "queue is empty\n";
		else {
			front = (front + 1) % _size;
			total--;
		}
	}

	bool empty() {
		return total == 0;
	}

	bool isFull() {
		return total == _size;
	}

	int size() {
		return total;
	}
};

pos dir[4] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int N, L, R;
int board[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
Queue <pos> tmp;
Queue <pos> group;

void* memset(void* dest, int data, size_t count) {
	for (size_t i = 0; i < count; i++) {
		*((char*)dest + i) = data;
	}
	return dest;
}

bool isOutOfRange(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N) return false;
	return true;
}

bool movePopulation(pos start) {
	int num = 0;
	int sum = 0;

	tmp.push(start);
	visit[start.x][start.y] = true;
	while (!tmp.empty()) {
		pos curr = tmp.top();
		tmp.pop();
		group.push(curr);
		num++;
		sum += board[curr.x][curr.y];

		for (int d = 0; d < 4; d++) {
			pos next = curr + dir[d];
			if (isOutOfRange(next.x, next.y)) continue;
			int diff = DIFF(board[curr.x][curr.y], board[next.x][next.y]);
			if (!visit[next.x][next.y] && diff >= L && diff <= R) {
				visit[next.x][next.y] = true;
				tmp.push(next);
			}
		}
	}

	if (group.size() == 1) {
		group.pop();
		return false;
	}

	while (!group.empty()) {
		pos curr = group.top();
		group.pop();
		board[curr.x][curr.y] = sum / num;
	}

	return true;
}

void solve() {
	int answer = 0;
	while (1) {
		memset(visit, false, sizeof(visit));
		bool isChanged = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					if (movePopulation({ i, j }))
						isChanged = true;
				}
			}
		}

		if (!isChanged) break;
		answer++;
	}
	cout << answer << endl;
}

int main(void) {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	solve();
	return 0;
}