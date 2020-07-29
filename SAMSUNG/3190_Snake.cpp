#include <iostream>
using namespace std;
#define MAX 101
#define TIME_MAX 10500
#define LEFT 'L'
#define RIGHT 'D'
#define right 0

int n, k, l;
struct pos {
    int x, y;
    pos operator+(pos p2) {
        pos ret;
        ret.x = x + p2.x;
        ret.y = y + p2.y;
        return ret;
    }
};

struct info {
    int time;
    char dir;
};

const pos direction[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };// right, left, up, down

pos apples[MAX];
info dir_info[MAX];

class Snake {
private:
    bool isEnded = false;
    int length = 1;
    int isApple[MAX][MAX] = { 0, };
    int isSnake[MAX][MAX] = { 0, };
    pos tailDirection[TIME_MAX] = { direction[right], };
    pos tail = { 1, 1 };
    pos head = { 1, 1 };
public:
    Snake(pos apples[MAX]) {
        for (int i = 0; i < k; i++) {
            int x = apples[i].x, y = apples[i].y;
            isApple[x][y] = 1;
        }
        isSnake[1][1] = 1;
        //printArray(isApple, n);
        setTailDirection();
    }

    void setTailDirection() {
        int t = 0;
        pos dir = direction[right];
        int info_idx = 0;
        for (t = 0; t < TIME_MAX; t++) {
            if (info_idx < l) {
                if (t == dir_info[info_idx].time) {
                    dir = getNextDirection(dir, dir_info[info_idx++].dir);
                }
                tailDirection[t] = dir;
            }
            else {
                tailDirection[t] = dir;
            }
        }
    }

    void printArray(int(*array)[MAX], int size) {
        printf("\n");
        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= size; j++) {
                printf("%d ", array[i][j]);
            }
            printf("\n");
        }

    }

    void move(pos curr, pos next, pos dir, int time) {
        if (isSnake[next.x][next.y]) {
            //crash
            isEnded = true;
            return;
        }

        isSnake[next.x][next.y] = 1;
        head = next;

        if (isApple[next.x][next.y]) {
            // it becomes longer
            length++;
            isApple[next.x][next.y] = 0;
        }
        else {
            // doesn't change and just move
            isSnake[tail.x][tail.y] = 0; 
            
            int tailTime = time - length + 1;
            pos tailDir = tailDirection[tailTime];
            tail = tail + tailDir;
        }
    }

    pos getNextDirection(pos curr_dir, char dir) {
        pos next_dir = { 0, 0 };
        if (dir == LEFT) {
            if (!curr_dir.x) next_dir = { -curr_dir.y, 0 };
            else next_dir = { 0, curr_dir.x };
        }
        else if (dir == RIGHT) {
            if (!curr_dir.x) next_dir = { curr_dir.y, 0 };
            else next_dir = { 0, -curr_dir.x };
        }
        return next_dir;
    }

    void proceed() {
        pos curr = { 1, 1 };
        pos next;
        pos dir;
        int t = 0;

        for (t = 0; ; t++) {
            dir = tailDirection[t];

            next = curr + dir;
            
            if (next.x >= 1 && next.x <= n && next.y >= 1 && next.y <= n) {
                move(curr, next, dir, t);
                curr = next;
            }
            else {
                isEnded = true;
            }
            
            if (isEnded) break;
           
        }
        printf("%d\n", t + 1);
    }
};

int main(void) {
    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> apples[i].x >> apples[i].y;
    }
    cin >> l;

    for (int i = 0; i < l; i++) {
        cin >> dir_info[i].time >> dir_info[i].dir;
    }

    Snake snake(apples);
    snake.proceed();
}