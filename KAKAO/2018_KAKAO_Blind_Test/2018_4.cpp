#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct Pos{
    int x, y;
    Pos operator+(Pos next){
        return {x + next.x, y + next.y};
    }
};
Pos Dir[4] = {{1, 0}, {0, 1}, {1, 1}};
int M, N;

bool getRemoveBlocks(vector<string> & board){
    vector<Pos> remove_list;

    for(int i = 0; i < M - 1; i++){
        for(int j = 0; j < N - 1; j++){
            char c = board[i][j];
            if (c == ' ') continue;
            bool canRemove = true;
            for(int d = 0; d < 3; d++){
                int x = i + Dir[d].x;
                int y = j + Dir[d].y;
                if (board[x][y] != c) {
                    canRemove = false;
                    break;
                }
            }
            if (canRemove) remove_list.push_back(Pos{i, j});
        }
    }

    if (remove_list.size() == 0)
        return false;

    for(auto r: remove_list){
        board[r.x][r.y] = ' ';
        for(int d = 0; d <3; d++){
            Pos next = r + Dir[d];
            board[next.x][next.y] = ' ';
        }
    }

    return true;
}

void shrink(vector<string> &board){
    for(int i = 0; i < N; i++){
        string s;
        for(int j = 0; j < M; j++){
            if (board[j][i] != ' '){
                s.push_back(board[j][i]);
            }
        }

        int num_blank = M - s.size();
        string blank = "";
        while(num_blank){
            blank += " ";
            num_blank--;
        }
        s = blank + s;

        for(int j = 0; j < M; j++){
            board[j][i] = s[j];
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    M = m; N= n;
    while(true){
        if (!getRemoveBlocks(board)) break;
        shrink(board);
    }

    for(auto bo : board){
        for(auto b : bo){
            if (b == ' '){
                answer++;
            }
        }
    }
    printf("%d\n", answer);

    return answer;
}