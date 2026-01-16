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
INCORRECT SOLUTION (illustrates marker overlap issue)

Idea:
    Use the first row and first column as in-place markers:
    - mat[i][0] == 0  ⇒ row i should be zeroed
    - mat[0][j] == 0  ⇒ column j should be zeroed

This idea is fundamentally correct and is used in the optimal O(1) space solution.

Why this implementation is incorrect:
    The problem arises specifically for the first row and the first column.
    They serve two roles simultaneously:
        (1) normal matrix data
        (2) marker storage

    For all i > 0 and j > 0, the markers are unambiguous:
        - mat[i][0] refers only to row i
        - mat[0][j] refers only to column j

    However, for index 0 there is an overlap:
        - mat[0][0] belongs to both the first row and the first column

    Once mat[0][0] is set to zero as a marker, the algorithm cannot distinguish:
        - whether row 0 should be zeroed,
        - whether column 0 should be zeroed,
        - or whether both were originally required to be zeroed.

    This ambiguity exists only for the first row and first column; all other
    rows and columns do not suffer from this overlap.

Example demonstrating the failure:

Input:
    1  0  3
    4  5  6
    7  8  9

Expected output:
    0  0  0
    4  0  6
    7  0  9

Execution:
    Encounter mat[0][1] == 0
    → mark row 0 and column 1:
        mat[0][0] = 0
        mat[0][1] = 0

    mat[0][0] is now zero, but it is unclear whether this indicates:
        - row 0 should be zeroed,
        - column 0 should be zeroed,
        - or both.

    During the zeroing pass, this ambiguity causes both the entire first row
    and the entire first column to be zeroed, producing an incorrect result.

Root cause:
    Marker overlap at mat[0][0] makes the zeroing intent for the first row
    and first column indistinguishable.

Correct approach:
    Handle the first row and first column explicitly by recording, before
    marking, whether they originally contain any zeros (e.g., using two
    boolean flags). All other rows and columns can safely use the first row
    and column as markers because no overlap exists for i > 0 and j > 0.
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