#include <algorithm>
#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// optimized bubble sort for already sorted array
void bubble_sort_optimized(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

int main() {
    std::vector<int> arr = {7, 2, 4, 1, 5, 3};

    bubble_sort(arr);

    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
