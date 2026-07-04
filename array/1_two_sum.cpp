/*
1. Two Sum

Time: O(n)
Space: O(n)

Key insight:
For each number x, look for target - x in a hash map of previously seen numbers.
*/

#include <iostream>
#include <unordered_map>
#include <utils.hpp>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.contains(complement)) {
                return {map[complement], i};
            }
            map.emplace(nums[i], i);
        }
        return {};
    }
};

int main() {
    Solution sol;

    int target1 = 9;
    int target2 = 6;
    int target3 = 6;
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {3, 2, 4};
    vector<int> nums3 = {3, 3};

    printVector(sol.twoSum(nums1, target1));
    printVector(sol.twoSum(nums2, target2));
    printVector(sol.twoSum(nums3, target3));
}