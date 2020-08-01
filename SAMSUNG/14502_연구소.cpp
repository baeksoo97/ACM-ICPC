#include <iostream>
using namespace std;
#define MAX_SIZE 8
#define MAX_NUM_VIRUS 11

struct pos {
    int x, y;
    void print() {
        cout << x << " " << y << endl;
    }
    pos operator+(pos second) {
        return { x + second.x, y + second.y };
    }
};

template<class T> class Queue {
private:
    int front_idx;
    int last_idx;
    int _size;
    T* values;
public:
    Queue() {
        _size = MAX_SIZE * MAX_SIZE;
        values = new T[_size];
        front_idx = 0;
        last_idx = -1;
    }

    ~Queue() {
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

int n, m;
int map[MAX_SIZE][MAX_SIZE];
pos virus[MAX_NUM_VIRUS];
int num_virus = 0;
pos dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

class Lab {
public:
    pos getPos(int idx) {
        pos ret = { idx / m, idx % m };
        return ret;
    }

    bool checkDuplicate(int i, int j, int k) {
        if (i == j || i == k || j == k) return true;
        else return false;
    }

    bool checkNotBlank(pos i, pos j, pos k) {
        if (!map[i.x][i.y] && !map[j.x][j.y] && !map[k.x][k.y])
            return false;
        else return true;
    }

    void setMapValue(pos i, pos j, pos k, int value) {
        map[i.x][i.y] = value;
        map[j.x][j.y] = value;
        map[k.x][k.y] = value;
    }

    void* memcopy(void* dest, void* src, size_t count) {
        for (size_t i = 0; i < count; i++) {
            *((char*)dest + i) = *((char*)src + i);
        }
        return dest;
    }

    int getSafeSize() {
        Queue <pos> q;
        for (int v = 0; v < num_virus; v++) {
            q.push(virus[v]);
        }

        int tmp[MAX_SIZE][MAX_SIZE];
        memcopy(tmp, map, sizeof(map));

        while (!q.empty()) {
            pos curr = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                pos next = curr + dir[d];
                if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m) {
                    if (tmp[next.x][next.y] == 0) {
                        tmp[next.x][next.y] = 2;
                        q.push(next);
                    }
                }
            }
        }

        int safe_size = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp[i][j] == 0)
                    safe_size++;
            }
        }

        return safe_size;
    }

    void solve() {
        int answer = 0;
        for (int i = 0; i < n * m; i++) {
            for (int j = 0; j < n * m; j++) {
                for (int k = 0; k < n * m; k++) {
                    if (checkDuplicate(i, j, k)) continue;
                    pos pos_i = getPos(i);
                    pos pos_j = getPos(j);
                    pos pos_k = getPos(k);

                    if (checkNotBlank(pos_i, pos_j, pos_k)) continue;
                    setMapValue(pos_i, pos_j, pos_k, 1);
                    int safe_size = getSafeSize();
                    setMapValue(pos_i, pos_j, pos_k, 0);

                    if (answer < safe_size)
                        answer = safe_size;
                }
            }
        }
        cout << answer << endl;
    }
};

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus[num_virus++] = { i, j };
            }
        }
    }
    Lab lab;
    lab.solve();
    return 0;
}