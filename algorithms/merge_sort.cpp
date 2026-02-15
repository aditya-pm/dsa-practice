#include <iostream>
#include <vector>

void merge(const std::vector<int>& left, const std::vector<int>& right, std::vector<int>& arr) {
    int nL = left.size();
    int nR = right.size();

    int i, j, k;
    i = j = k = 0;

    while (i < nL && j < nR)
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];

    while (i < nL)
        arr[k++] = left[i++];

    while (j < nR)
        arr[k++] = right[j++];
}

void merge_sort(std::vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return;

    int mid = n / 2;
    std::vector<int> left(mid);
    std::vector<int> right(n - mid);

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < n; i++)
        right[i - mid] = arr[i];

    merge_sort(left);
    merge_sort(right);
    merge(left, right, arr);
}

int main() {
    std::vector<int> arr = {2, 4, 1, 6, 8, 5, 3, 7};
    merge_sort(arr);

    for (int x : arr) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
