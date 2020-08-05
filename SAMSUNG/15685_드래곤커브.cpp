#include<iostream>
using namespace std;
#define MAX_SIZE 101
#define MAX_DRAGON_NUM 21
#define MAX_POINT 10001

struct pos {
    int x, y;
    pos operator+(pos second) {
        return { x + second.x, y + second.y };
    }
    pos operator-(pos second) {
        return { x - second.x, y - second.y };
    }
};

struct DragonCurve {
    pos start;
    int direction;
    int generation;
    pos points[MAX_POINT];
    int num_points = 0;
};

int N;
const pos DIR[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
DragonCurve dc[MAX_DRAGON_NUM];

class Program {
private:
    int board[MAX_SIZE][MAX_SIZE] = { 0, };
public:
    pos rotateClockwise(pos src) {
        return { -src.y, src.x };
    }

    void setBoard(int idx) {
        int num_points = dc[idx].num_points;
        for (int i = 1; i <= num_points; i++) {
            pos point = dc[idx].points[i];
            if (point.x >= 0 && point.x < MAX_SIZE && point.y >= 0 && point.y < MAX_SIZE)
                board[point.x][point.y] = 1;
        }
    }

    void setPoints(int idx, int cnt) {
        if (cnt > dc[idx].generation) {
            setBoard(idx);
            return;
        }

        int num_points = dc[idx].num_points;
        pos end_point = dc[idx].points[num_points];

        for (int i = num_points - 1; i >= 1; i--) {
            pos curr = dc[idx].points[i];
            curr = end_point + rotateClockwise(curr - end_point);
            dc[idx].points[++dc[idx].num_points] = curr;
        }
        setPoints(idx, cnt + 1);
        return;
    }

    int getAnswer() {
        int cnt = 0;
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            for (int j = 0; j < MAX_SIZE - 1; j++) {
                if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                    cnt++;
            }
        }
        return cnt;
    }

    void solve() {
        for (int i = 1; i <= N; i++) {
            dc[i].points[++dc[i].num_points] = dc[i].start;
            dc[i].points[++dc[i].num_points] = dc[i].start + DIR[dc[i].direction];
            setPoints(i, 1);
        }
        int answer = getAnswer();
        cout << answer << endl;
    }
};

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        dc[i].start = { x, y };
        dc[i].direction = d;
        dc[i].generation = g;
    }
    Program program;
    program.solve();
    return 0;
}