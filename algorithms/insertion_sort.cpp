#include <iostream>
#include <vector>

// some people call hole as key too

void insertion_sort_for(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int hole;
        for (hole = i; hole > 0; hole--) {
            if (arr[hole - 1] > key) {
                arr[hole] = arr[hole - 1];
            } else {
                break;
            }
        }
        arr[hole] = key;
    }
}

void insertion_sort_while(std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; i++) {
        int value = arr[i];
        int hole = i;
        while (hole > 0 && arr[hole - 1] > value) {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = value;
    }
}

int main() {
    std::vector<int> arr = {7, 2, 4, 1, 5, 3};

    insertion_sort_for(arr);
    insertion_sort_while(arr);

    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
