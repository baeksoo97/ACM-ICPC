#include <iostream>
using namespace std;
#define INF 1e9
#define MAX_SIZE 50
#define MAX_NUM 11
#define BLANK 0
#define WALL -1
#define ACTIVE -2
#define INACTIVE -4

template <class T> class Queue {
private:
    int total = 0;
    int _size = 0;
    int front = 0;
    int rear = 0;
    T* values;
public:
    Queue() {
        _size = MAX_SIZE * MAX_SIZE;
        values = new T[_size];
    }
    ~Queue() {
        delete[]values;
    }
    bool empty() {
        return total == 0;
    }
    bool isFull() {
        return total == _size;
    }
    void push(T value) {
        if (!isFull()) {
            total++;
            values[rear] = value;
            rear = (rear + 1) % _size;
        }
    }
    void pop() {
        if (!empty()) {
            total--;
            front = (front + 1) % _size;
        }
    }
    T top() {
        if (!empty()) return values[front];
    }
    int size() {
        return total;
    }
};

struct pos {
    int x, y;
    pos operator+(pos second) {
        return { x + second.x, y + second.y };
    }
};

pos dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N, M;
int board[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
pos virus[MAX_NUM];
Queue <pair<int, pos>> q;
int num_virus = 0, num_blank = 0;
int selected[MAX_NUM];
int answer = INF;

void* memcpy(void* dest, void* src, size_t count) {
    for (size_t i = 0; i < count; i++) {
        *((char*)dest + i) = *((char*)src + i);
    }
    return dest;
}

void diffuse() {
    int total_time = 0, diffuse_space = 0; 
    memcpy(visit, board, sizeof(board));

    for (int i = 0; i < M; i++) {
        pos p = virus[selected[i]];
        q.push({ 0, p });
        visit[p.x][p.y] = ACTIVE;
    }

    while (!q.empty()) {
        int curr_time = q.top().first;
        pos curr = q.top().second;
        q.pop();
        
        if (board[curr.x][curr.y] != INACTIVE && total_time < curr_time)
            total_time = curr_time; 

        for (int d = 0; d < 4; d++) {
            pos next = curr + dir[d];
            if (next.x >= 0 && next.x < N && next.y >= 0 && next.y < N) {
                int next_num = visit[next.x][next.y];
                if (next_num == BLANK || next_num == INACTIVE) {
                    visit[next.x][next.y] = curr_time + 1;  
                    q.push({ curr_time + 1 , next });
                    if (next_num == BLANK) diffuse_space++;
                }
            }
        }
    }

    if (diffuse_space == num_blank) {
        if (total_time < answer) answer = total_time;
    }

    return;
}

void selectVirus(int cnt, int idx) {
    if (cnt >= M) {
        diffuse();
        return;
    }

    for (int i = idx + 1; i < num_virus; i++) {
        selected[cnt] = i;
        selectVirus(cnt + 1, i);
    }
}

void solve() {
    selectVirus(0, -1);
    if (answer == INF) cout << -1 << endl;
    else cout << answer << endl;
}

int main(void) {
    cin >> N >> M;
    int a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a;
            if (a == 2) {
                virus[num_virus++] = { i, j };
                a = INACTIVE;
            }
            else if (a == 1) a = WALL;
            else if (a == 0) num_blank++;
            board[i][j] = a;
        }
    }
    solve();
    return 0;
}
