#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Lomuto partition
int partition(int* arr, int start, int end) {
    int pivot = arr[end];  // assume last element to be the pivot
    int partition_index = start;

    // iterate upto but not including the pivot
    for (int i = start; i < end; i++) {
        // move elements smaller than pivot to the left partition
        if (arr[i] < pivot) {
            swap(&arr[i], &arr[partition_index]);

            partition_index++;
        }
    }

    // swap pivot into its correct sorted position
    swap(&arr[end], &arr[partition_index]);

    return partition_index;
}

// TODO: add Hoarse partition

void quick_sort(int* arr, int start, int end) {
    if (start >= end) return;

    int partition_index = partition(arr, start, end);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5, 3, 4};
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, arr_len - 1);

    for (int i = 0; i < arr_len; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}