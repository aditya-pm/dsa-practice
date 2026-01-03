// 88. Merge Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

int main() {
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {4, 5, 6};

    Solution solution;
    solution.merge(v1, 3, v2, 3);

    for (int num : v1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
