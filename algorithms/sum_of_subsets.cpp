#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& arr, int i, int sum, int target, vector<int>& subset) {
    if (sum == target) {
        for (int x : subset)
            cout << x << " ";
        cout << endl;
        return;
    }

    if (i == arr.size() || sum > target)
        return;

    // include element
    subset.push_back(arr[i]);
    solve(arr, i + 1, sum + arr[i], target, subset);
    subset.pop_back();  // backtrack

    // exclude element
    solve(arr, i + 1, sum, target, subset);
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 5;

    vector<int> subset;
    solve(arr, 0, 0, target, subset);
}