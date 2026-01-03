// 189. Rotate Array
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> nums2 = nums;
        for (int i = 0; i < size; i++) {
            nums[(i + k) % size] = nums2[i];
        }
    }

    void rotate2(vector<int>& nums, int k) {
        int n = nums.size();
        if (n <= 1) return;
        k = k % n;
        // reverse entire arr
        for (int i = 0; i < n / 2; i++) {
            swap(nums[i], nums[n - 1 - i]);
        }
        // reverse subarray [0,.., k - 1]
        for (int i = 0; i < k / 2; i++) {
            swap(nums[i], nums[k - 1 - i]);
        }
        // reverse subarray [k, ...]
        for (int i = k; i < k + (n - k) / 2; i++) {
            swap(nums[i], nums[n - 1 - (i - k)]);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate2(nums, 3);
    cout << endl;

    return 0;
}