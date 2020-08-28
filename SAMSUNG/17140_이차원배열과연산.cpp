#include <iostream>
#include <queue>
using namespace std;
#define MAX_NUM 100
typedef pair<int, int> pii;
int R, C, K;
int board[MAX_NUM][MAX_NUM];
int num_r = 3, num_c = 3;
int cnt[MAX_NUM + 1] = { 0, };
priority_queue <pii, vector<pii>, greater<pii>> q;

void sort() {
    int max_idx = 0;

    int I, J;
    if (num_r >= num_c) I = num_r, J = num_c;
    else I = num_c, J = num_r;

    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            if (num_r >= num_c)
                cnt[board[i][j]]++, board[i][j] = 0;
            else
                cnt[board[j][i]]++, board[j][i] = 0;
        }

        for (int i = 1; i <= 100; i++) {
            if (cnt[i]) {
                q.push({ cnt[i], i });
                cnt[i] = 0;
            }
        }

        int idx = 0;
        while (!q.empty()) {
            int amount = q.top().first;
            int num = q.top().second;
            q.pop();
            if (idx >= 100) continue;
            if (num_r >= num_c)
                board[i][idx++] = num, board[i][idx++] = amount;
            else
                board[idx++][i] = num, board[idx++][i] = amount;
        }

        if (idx > max_idx) max_idx = idx;
    }

    if (num_r >= num_c) num_c = max_idx;
    else num_r = max_idx;
}

void printBoard(int max) {
    cout << endl;
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    int answer = 0;
    for (; answer <= 100; answer++) {
        if (board[R][C] == K) {
            break;
        }
        sort();
    }
    if (answer > 100) cout << -1 << endl;
    else cout << answer << endl;
}

int main(void) {
    cin >> R >> C >> K;
    R--;
    C--;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }
    solve();
    return 0;
}