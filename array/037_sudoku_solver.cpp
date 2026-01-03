#include <vector>
using namespace std;

class Solution {
   public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // check row
        for (int x = 0; x < 9; x++)
            if (board[row][x] == num) return false;

        // check col
        for (int y = 0; y < 9; y++)
            if (board[y][col] == num) return false;

        // check 3x3 box
        int boxStartRow = row - (row % 3);
        int boxStartCol = col - (col % 3);
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[boxStartRow + r][boxStartCol + c] == num) return false;
            }
        }

        return true;
    }

    bool backTrack(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char guess = '1'; guess <= '9'; guess++) {
                        if (isValid(board, row, col, guess)) {
                            board[row][col] = guess;

                            if (backTrack(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backTrack(board);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    return 0;
}
