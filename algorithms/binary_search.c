#include <stdio.h>

void binary_search(int target, int* arr, int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // int mid = (left + right) / 2;
        int mid = left + (right - left) / 2;
        if (target == arr[mid]) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (target > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Element not found!\n");
}

void binary_search_recursive(int target, int* arr, int left, int right) {
    if (left > right) {
        printf("Element not found!\n");
        return;
    }

    // int mid = (left + right) / 2;
    int mid = left + (right - left) / 2;

    if (target == arr[mid]) {
        printf("Element found at index %d\n", mid);
        return;
    } else if (target > arr[mid]) {
        binary_search_recursive(target, arr, mid + 1, right);
    } else {
        binary_search_recursive(target, arr, left, mid - 1);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    binary_search(9, arr, 9);
    binary_search_recursive(9, arr, 0, 8);

    binary_search(1, arr, 9);
    binary_search_recursive(1, arr, 0, 8);

    binary_search(10, arr, 9);
    binary_search_recursive(10, arr, 0, 8);

    return 0;
}
