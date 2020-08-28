#include <iostream>
using namespace std;
const int MAX = 21;
int board[MAX][MAX];
int n;
int answer;

template<class T> class Stack
{
private:
    int top_idx;
    int _size;
    T* values;

public:
    Stack() {
        _size = MAX;
        values = new T[_size];
        top_idx = -1;
    }

    ~Stack() {
        delete[] values;
    }

    void push(T value) {
        if (!isFull()) values[++top_idx] = value;
        else printf("stack is full\n");
    }

    void pop() {
        if (!empty()) top_idx--;
        else printf("stack is empty\n");
    }

    T top() {
        if (!empty()) return values[top_idx];
    }

    bool empty() {
        if (top_idx < 0) return true;
        else return false;
    }

    bool isFull() {
        if (top_idx + 1 == _size) return true;
        else return false;
    }

    int size() {
        return top_idx + 1;
    }
};

void* copyArray(void* dest, const void* src, size_t count) {
    for (size_t i = 0; i < count; i++)
        *((char*)dest + i) = *((char*)src + i);
    return dest;
}

int findMax() {
    int max_block = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (max_block < board[i][j])
                max_block = board[i][j];
        }
    }
    return max_block;
}

void setArray(int arr[MAX], int col, int row) {
    if (col >= 0) {
        for (int i = 0; i < n; i++) {
            arr[i] = board[col][i];
        }
    }
    else if (row >= 0) {
        for (int i = 0; i < n; i++) {
            arr[i] = board[i][row];
        }
    }
}

void updateBoard(int size, int new_arr[MAX], int col, int row) {
    for (int i = 0; i < size; i++) {
        if (col >= 0)
            board[col][i] = new_arr[i];
        else if (row >= 0)
            board[i][row] = new_arr[i];
    }

    for (int i = size; i < n; i++) {
        if (col >= 0)
            board[col][i] = 0;
        else if (row >= 0)
            board[i][row] = 0;
    }
}

void move(int col, int row) {
    int arr[MAX];
    setArray(arr, col, row);

    Stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        if (num == 0)
            continue;
        if (st.size() == 0) {
            st.push({ 0, num });
            continue;
        }

        int top = st.top().second;
        int is_visited = st.top().first;
        if (is_visited || top != num) {
            st.push({ 0, num });
        }
        else if (top == num) {
            st.pop();
            st.push({ 1, num * 2 });
        }
    }

    int size = st.size();
    int new_arr[MAX];

    for (int i = 0; i < size; i++) {
        new_arr[size - i - 1] = st.top().second;
        st.pop();
    }
    updateBoard(size, new_arr, col, row);
}

void swapBoard(int direction) {
    int tmpBoard[MAX][MAX];

    copyArray(tmpBoard, board, sizeof(board));
    if (direction == 0) {
        // Up down
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = tmpBoard[n - i - 1][j];
            }
        }
    }
    else if (direction == 1) {
        // Left Right
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = tmpBoard[i][n - j - 1];
            }
        }
    }
}

void moveDown() {
    swapBoard(0);
    for (int i = 0; i < n; i++) {
        move(-1, i);
    }
    swapBoard(0);
}

void moveRight() {
    swapBoard(1);
    for (int i = 0; i < n; i++) {
        move(i, -1);
    }
    swapBoard(1);
}

void moveUp() {
    for (int i = 0; i < n; i++) {
        move(-1, i);
    }
}

void moveLeft() {
    for (int i = 0; i < n; i++) {
        move(i, -1);
    }
}

void mover(int option) {
    if (option == 0) moveDown();
    else if (option == 1) moveRight();
    else if (option == 2) moveUp();
    else if (option == 3) moveLeft();
}

void doRecursive(int cnt) {
    if (cnt == 5) {
        int max_block = findMax();
        if (answer < max_block) answer = max_block;
        return;
    }

    int tmp[MAX][MAX];
    copyArray(tmp, board, sizeof(board));
    for (int i = 0; i < 4; i++) {
        mover(i);
        doRecursive(cnt + 1);
        copyArray(board, tmp, sizeof(tmp));
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    doRecursive(0);
    printf("%d\n", answer);

    return 0;
}

