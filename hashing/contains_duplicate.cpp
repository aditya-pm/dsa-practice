// 217. Contains Duplicate
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    // bad
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (count.count(num) > 0) {
                count[num]++;
            } else {
                count[num] = 1;
            }
        }
        for (const auto& pair : count) {
            if (pair.second > 1) return true;
        }
        return false;
    }

    // good
    bool containsDuplicate2(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
    }

    // even better
    bool containsDuplicate3(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}