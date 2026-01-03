// 26. Remove Duplicates From Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    // worst solution
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end();) {
            if (*it == curr) {
                it = nums.erase(it);
            } else {
                curr = *it;
                it++;
            }
        }
        return nums.size();
    }

    int removeDuplicates2(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1]) nums[k++] = nums[i];
        return k;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int newLength = solution.removeDuplicates2(nums);
    cout << newLength << endl;

    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
