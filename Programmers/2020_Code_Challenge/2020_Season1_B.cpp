#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int snails[1001][1001];

    int tmp_n = n;
    int start = 1;
    int end = n;
    int d_xpos = 1, d_ypos = 1, r_xpos = n, r_ypos = 2, u_xpos = n - 1, u_ypos = n - 1;
    char dir = 'd';

    while (true) {
        if (tmp_n == 0) break;
        if (dir == 'd') {
            int x_pos = d_xpos, y_pos = d_ypos;
            for (int i = start; i <= end; i++) {
                snails[x_pos++][y_pos] = i;
            }
            dir = 'r';
            d_xpos += 2;
            d_ypos++;
        }
        else if (dir == 'r') {
            int x_pos = r_xpos, y_pos = r_ypos;
            for (int i = start; i <= end; i++) {
                snails[x_pos][y_pos++] = i;
            }
            dir = 'u';
            r_xpos--;
            r_ypos++;
        }
        else if (dir == 'u') {
            int x_pos = u_xpos, y_pos = u_ypos;
            for (int i = start; i <= end; i++) {
                snails[x_pos--][y_pos--] = i;
            }
            dir = 'd';
            u_xpos--;
            u_ypos -= 2;
        }

        start = end + 1;
        end = end + (--tmp_n);

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            answer.push_back(snails[i][j]);
        }
    }

    return answer;
}