/*
 * Rotate an N x N matrix by 90 degrees clockwise IN-PLACE.
 *
 * Core Idea: Layer-by-Layer Rotation
 * ---------------------------------
 * We treat the matrix as concentric square "layers" (or rings).
 * Each layer is rotated independently.
 *
 * Example: 5 x 5 matrix (indices shown)
 *
 *   Layer 0 (outer):
 *   (0,0)  (0,1)  (0,2)  (0,3)  (0,4)
 *   (1,0)                       (1,4)
 *   (2,0)                       (2,4)
 *   (3,0)                       (3,4)
 *   (4,0)  (4,1)  (4,2)  (4,3)  (4,4)
 *
 *   Layer 1 (inner):
 *           (1,1)  (1,2)  (1,3)
 *           (2,1)         (2,3)
 *           (3,1)  (3,2)  (3,3)
 *
 * Number of layers = n / 2
 *
 * For a given layer `i`:
 *   - first index = i
 *   - last index  = n - 1 - i
 *
 * We iterate ONLY over the top edge of the current layer:
 *   (i, j) where j goes from i to n - 1 - i - 1
 *
 * Each iteration performs ONE 4-way cyclic swap:
 *
 *   left   -> top
 *   bottom -> left
 *   right  -> bottom
 *   top    -> right
 *
 * This rotates the layer clockwise by 90 degrees.
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

void rotate_matrix(std::vector<std::vector<int>>& mat) {
    size_t n = mat.size();

    for (size_t i = 0; i < n / 2; i++) {
        size_t first = i;
        size_t last = n - 1 - i;

        for (size_t j = first; j < last; j++) {
            int temp = mat[first][j];

            // left -> top
            mat[first][j] = mat[n - 1 - j][first];
            // bottom -> left
            mat[n - 1 - j][first] = mat[last][n - 1 - j];
            // right -> bottom
            mat[last][n - 1 - j] = mat[j][last];
            // top (temp) -> right
            mat[j][last] = temp;
        }
    }
}

void rotate_matrix2(std::vector<std::vector<int>>& mat) {
    size_t n = mat.size();

    // transpose
    for (size_t i = 0; i < n; i++) {
        // j == i is diagonal, swap useless.
        // swap for only j > i or j < i (here j > i is used) to prevent
        // undo of the swap
        for (size_t j = i + 1; j < n; j++) {
            std::swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse each row (horizontal flip)
    for (size_t i = 0; i < n; i++) {
        std::reverse(mat[i].begin(), mat[i].end());
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
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    print_matrix(matrix);

    rotate_matrix(matrix);
    std::cout << std::endl;

    print_matrix(matrix);

    return 0;
}
