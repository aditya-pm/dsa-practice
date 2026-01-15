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