#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct info {
    bool pillar = 0; 
    bool beam = 0;
};
int N;

bool check(int x, int y) {
    if (x >= 0 && x <= N && y >= 0 && y <= N) return true;
    else return false;
}

bool isPillarRight(vector<vector<info>> board, int x, int y) {
    if (check(x, y) && y == 0) return true;
    else if (check(x, y-1) && board[x][y - 1].pillar) return true;
    else if ((check(x-1, y) && board[x - 1][y].beam) ||
        (check(x, y) && board[x][y].beam)) return true;

    return false;
}

bool isBeamRight(vector<vector<info>> board, int x, int y) {
    if ((check(x, y-1) && board[x][y - 1].pillar) || 
        (check(x+1, y-1)&&board[x + 1][y - 1].pillar))
        return true;
    else if ((check(x-1, y) &&board[x - 1][y].beam)
        && (check(x+1, y) && board[x + 1][y].beam))
        return true;
    return false;
}

void buildPillar(vector<vector<info>>& board, int x, int y) {
    //printf("build pillar %d %d\n", x, y);
    if (isPillarRight(board, x, y))
        board[x][y].pillar = 1;
}

void buildBeam(vector<vector<info>>& board, int x, int y) {
    //printf("build beam %d %d\n", x, y);
    if (isBeamRight(board, x, y))
        board[x][y].beam = 1;
}

void removePillar(vector<vector<info>>& board, int x, int y) {
    //printf("removePillar %d %d\n", x, y);
    int tmp = board[x][y].pillar;
    board[x][y].pillar = 0;
    bool enable = true;
    if (check(x, y + 1) && board[x][y + 1].beam) {
        if (!isBeamRight(board, x, y + 1)) enable = false;
    }
    if (check(x-1, y+1) && board[x - 1][y + 1].beam) {
        if (!isBeamRight(board, x - 1, y + 1)) enable = false;
    }
    if (check(x, y +1) && board[x][y + 1].pillar) {
        if (!isPillarRight(board, x, y + 1)) enable = false;
    }
    if (!enable) board[x][y].pillar = tmp;
}

void removeBeam(vector<vector<info>>& board, int x, int y) {
    //printf("removeBeam %d %d\n", x, y);
    int tmp = board[x][y].beam;
    board[x][y].beam = 0;
    bool enable = true;
    // left beam
    if (check(x-1, y) && board[x - 1][y].beam) {
        if (!isBeamRight(board, x - 1, y)) enable = false;
    }
    if (check(x+1, y) && board[x + 1][y].beam) {
        if (!isBeamRight(board, x + 1, y)) enable = false;
    }
    if (check(x, y) && board[x][y].pillar) {
        if (!isPillarRight(board, x, y)) enable = false;
    }
    if (check(x+1, y) && board[x + 1][y].pillar){
        if (!isPillarRight(board, x + 1, y)) enable = false;
    }

    if (!enable) board[x][y].beam = tmp;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<info>> board(n + 1, vector<info>(n + 1));
    N = n;
    for (auto frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2]; // 0 : pillar, 1 : beam
        int b = frame[3]; // 0 : remove, 1 : add
        if (a == 0) {
            if (b == 0) removePillar(board, x, y);
            else if (b == 1) buildPillar(board, x, y);
        }
        else if (a == 1) {
            if (b == 0) removeBeam(board, x, y);
            else if (b == 1) buildBeam(board, x, y);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (board[i][j].pillar) 
                answer.push_back({ i , j , 0 });
            if (board[i][j].beam) 
                answer.push_back({ i , j , 1 });
        }
    }

    return answer;
}

int main(void) {
    int n = 5; 
    vector<vector<int>> build_frame = {{1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1}};

    solution(n, build_frame);
    build_frame = { {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} };
    solution(n, build_frame);
}