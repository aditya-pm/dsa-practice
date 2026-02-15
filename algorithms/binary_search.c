#include <stdio.h>

void binary_search(int target, int* arr, int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            printf("Element found at index %d\n", mid);
            return;
        } else if (arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("Element not found!\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    binary_search(8, arr, 9);

    return 0;
}
