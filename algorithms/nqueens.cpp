#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // check column
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solve(int row, vector<vector<int>>& board, int n) {
    if (row == n) {
        // print solution
        for (auto& r : board) {
            for (int x : r)
                cout << x << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;       // place queen
            solve(row + 1, board, n);  // recurse
            board[row][col] = 0;       // backtrack
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, board, n);
}