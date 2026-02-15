#include <algorithm>
#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int start, int end) {
    int pivot = arr[end];
    int partition_index = start;  // set partition index as start initially

    for (int i = start; i < end; i++) {
        // swap if element is lesser than pivot
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[partition_index]);
            partition_index++;
        }
    }

    // swap pivot with element at partition index
    std::swap(arr[partition_index], arr[end]);

    return partition_index;
}

void quick_sort(std::vector<int>& arr, int start, int end) {
    if (start >= end) return;

    int partition_index = partition(arr, start, end);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

int main() {
    std::vector<int> arr = {2, 4, 1, 6, 8, 5, 3, 7};
    quick_sort(arr, 0, arr.size() - 1);

    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
