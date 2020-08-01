#include <iostream>
using namespace std;
#define MAX_MAP_SIZE 500
#define MAX_TETROMINO_NUM 7

struct pos {
    int x, y;
    void print() {
        printf("%d %d\n", x, y);
    }

    pos operator+(pos second) {
        return { x + second.x, y + second.y };
    }
};

int n, m;
int map[MAX_MAP_SIZE][MAX_MAP_SIZE];
pos dir[4] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
pos tetromino[MAX_TETROMINO_NUM][4] = {
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // |
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, // ¤¡
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, // ¤©
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, //¤Ì
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}}
};

bool checkOutOfRange(pos curr);
int getSum(pos curr[4]);
void solve();

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    solve();

    return 0;
}

bool checkOutOfRange(pos curr) {
    int x = curr.x, y = curr.y;
    if (x >= 0 && x < n && y >= 0 && y < m) return false;
    else return true;
}

int getSum(pos curr[4]) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        if (!checkOutOfRange(curr[i])) {
            sum += map[curr[i].x][curr[i].y];
        }
        else {
            sum = 0;
        }
    }
    return sum;
}

void solve() {
    int answer = 0;
    for (int i = 0; i < MAX_TETROMINO_NUM; i++) {
        pos* prev = tetromino[i];
        for (int r = 0; r < 4; r++) {
            pos curr[4];

            //rotate previous tetromino
            for (int j = 0; j < 4; j++) {
                curr[j] = { prev[j].y, -prev[j].x };
            }

            for (int _n = 0; _n < n; _n++) {
                for (int _m = 0; _m < m; _m++) {
                    pos moved_curr[4];
                    for (int t = 0; t < 4; t++) {
                        moved_curr[t] = curr[t] + pos{ _n, _m };
                    }
                    int sum = getSum(moved_curr);

                    if (answer < sum) {
                        answer = sum;
                    }
                }
            }

            prev = curr;
        }
    }

    cout << answer << endl;
}
