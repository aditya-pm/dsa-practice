#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// caller guarantees valid input
Matrix matrix_multiply(const Matrix& matA, const Matrix& matB) {
    int rowsA = matA.size();
    int colsA = matA[0].size();
    int colsB = matB[0].size();

    Matrix matC(rowsA, std::vector<int>(colsB));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < colsA; k++) {
                sum += matA[i][k] * matB[k][j];
            }
            matC[i][j] = sum;
        }
    }

    return matC;
}

void print_matrix(const Matrix& mat) {
    for (std::vector<int> row : mat) {
        for (int x : row) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix matA = {{1, 2, 3}, {4, 5, 6}};
    Matrix matB = {{10, 11}, {20, 21}, {30, 31}};

    Matrix matC = matrix_multiply(matA, matB);

    print_matrix(matC);

    return 0;
}
