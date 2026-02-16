#include <algorithm>
#include <iostream>
#include <vector>

// Lomuto partition
int partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int partition_index = start;  // set partition index as start initially

    // iterate upto but not including the pivot
    for (int i = start; i < end; i++) {
        // move elements smaller than pivot to the left partition
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[partition_index]);
            partition_index++;
        }
    }

    // swap pivot into its correct sorted position
    std::swap(arr[partition_index], arr[end]);

    return partition_index;
}

// TODO: add Hoarse partition

void quick_sort(std::vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int partition_index = partition(arr, start, end);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    quick_sort(arr, 0, arr.size() - 1);

    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
