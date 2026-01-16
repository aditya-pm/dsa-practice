#include <iostream>
#include <unordered_set>
#include <vector>

void zero_matrix(std::vector<std::vector<int>>& mat) {
    std::unordered_set<int> zero_rows;
    std::unordered_set<int> zero_cols;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (zero_rows.count(i) || zero_cols.count(j)) mat[i][j] = 0;
        }
    }
}

/*
INCORRECT SOLUTION (demonstrates a common pitfall)

Idea:
    Use the first column and first row of the matrix as in-place markers:
    - mat[i][0] == 0  → row i should be zeroed
    - mat[0][j] == 0  → column j should be zeroed

This idea itself is correct and is the basis of the optimal O(1) space solution.

Why the implementation is incorrect:
    The first row and first column are used both as:
        (1) normal data
        (2) marker storage

    However, the algorithm does NOT preserve whether the first row or first
    column originally contained a zero. Once they are overwritten as markers,
    their original state is lost, and the program can no longer distinguish:
        - cells that were originally zero
        - cells that were set to zero later as markers

    This causes incorrect propagation of zeros.

Concrete example illustrating the failure:

Input:
    1  0  3
    4  5  6
    7  8  9

Expected output:
    0  0  0
    4  0  6
    7  0  9

Execution (first pass — marking phase):
    Encounter mat[0][1] == 0
    → mark row 0 and column 1:
        mat[0][0] = 0
        mat[0][1] = 0

Matrix becomes:
    0  0  3
    4  5  6
    7  8  9

Critical loss of information:
    mat[0][0] is now zero, but the algorithm does not know whether:
        - it was originally zero, or
        - it was set to zero as a marker

Execution (second pass — zeroing phase):
    For row 0:
        mat[0][0] == 0 → condition is true for all columns
        → entire row 0 is zeroed

    For column 0:
        mat[0][0] == 0 → condition is true for all rows
        → entire column 0 is zeroed

Final (incorrect) matrix:
    0  0  0
    0  0  6
    0  0  9

Root cause (core bug):
    The algorithm overwrites the first row and first column without first
    recording whether they originally needed to be zeroed. This violates
    a key invariant of in-place marking algorithms:
        "Marker memory must not destroy information that is still needed later."

Correct approach:
    Before using the first row and column as markers, store their original
    zero-state separately (e.g., using two boolean variables).
*/
void zero_matrix_incorrect(std::vector<std::vector<int>>& mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;  // mark row
                mat[0][j] = 0;  // mark column
            }
        }
    }

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
        }
    }
}

void zero_matrix2(std::vector<std::vector<int>>& mat) {
    if (mat.empty() || mat[0].empty()) return;

    int rows = mat.size();
    int cols = mat[0].size();

    bool zero_first_row = false;
    bool zero_first_col = false;

    // check if first row has to be zeroed
    for (int j = 0; j < cols; j++) {
        if (mat[0][j] == 0) {
            zero_first_row = true;
            break;
        }
    }

    // check if first col has to be zeroed
    for (int i = 0; i < rows; i++) {
        if (mat[i][0] == 0) {
            zero_first_col = true;
            break;
        }
    }

    // use first row and column as markers
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][j] == 0) {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    // zero matrix based on markers (excluding first row/col)
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // zero first row if needed
    if (zero_first_row) {
        for (int j = 0; j < cols; j++) {
            mat[0][j] = 0;
        }
    }

    // zero first column if needed
    if (zero_first_col) {
        for (int i = 0; i < rows; i++) {
            mat[i][0] = 0;
        }
    }
}

void print_matrix(const std::vector<std::vector<int>>& mat) {
    for (const auto& row : mat) {
        for (size_t j = 0; j < row.size(); j++) {
            std::cout << row[j] << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    // 2 * 3
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 0}};

    print_matrix(matrix);
    zero_matrix(matrix);
    std::cout << std::endl;
    print_matrix(matrix);

    return 0;
}