#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key) {
    int len_key = key.size();
    vector <vector<int>> next(len_key, vector<int>(len_key, 0));
    for (int i = 0; i < len_key; i++) {
        for (int j = 0; j < len_key; j++) {
            next[j][len_key - i - 1] = key[i][j];
        }
    }
    for (int i = 0; i < len_key; i++) {
        for (int j = 0; j < len_key; j++) {
            cout << next[i][j] << " ";
        }
        cout << endl;
    }
    return next;
}

int canOpen(int num_hole, vector<vector<int>> key, vector<vector<int>> lock, int x, int y) {
    int len_key = key.size();
    int len_lock = lock.size();
    //cout << "start " << x<< " , " << y << endl;
    for (int i = 0; i < len_key; i++) {
        for (int j = 0; j < len_key; j++) {
            if (x + i < 0 || x + i >= len_lock 
                || y + j < 0 || y + j >= len_lock) continue;
            if (key[i][j] == 1 && lock[x + i][y + j] == 0) {
                num_hole--;
                continue;
            }
            if (key[i][j] == 0 && lock[x + i][y + j] == 1) { 
                continue;
            }
            else {
                return -1;
            }
        }
    }

    return num_hole;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int len_key = key.size();
    int len_lock = lock.size();
    int num_hole = 0; 

    for (int i = 0; i < len_lock; i++) {
        for (int j = 0; j < len_lock; j++) {
            if (lock[i][j] == 0) num_hole++;
        }
    }

    for (int r = 0; r < 4; r++) {
        for (int i = -len_key + 1; i < len_lock; i++) {
            for (int j = -len_key + 1; j < len_lock; j++) {
                int remain = canOpen(num_hole, key, lock, i, j);
                if (remain == 0) {
                    answer = true;
                    return answer;
                }
            }
        }
        key = rotate(key);
    }
    return answer;
}

int main(void) {
    vector <vector<int>> key = {{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector <vector<int>> lock = {{1, 1, 1}, {1, 1, 0}, {1,0, 1}};

    solution(key, lock);
    
    return 0; 
}