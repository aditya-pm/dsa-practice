#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // pair = num, freq
        unordered_map<int, int> freq;
        vector<pair<int, int>> freqPairs;

        for (int num : nums) freq[num]++;

        for (const auto& [num, count] : freq)
            freqPairs.emplace_back(num, count);

        sort(freqPairs.begin(), freqPairs.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> top;
        for (int i = 0; i < k; i++)
            top.push_back(freqPairs[i].first);

        return top;
    }

    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        vector<vector<int>> bucket(nums.size() + 1);

        for (const auto& [num, count] : freq)
            bucket[count].push_back(num);

        vector<int> result;

        for (int f = nums.size(); f >= 1; f--) {
            for (int num : bucket[f]) {
                result.push_back(num);

                if (result.size() == k)
                    return result;
            }
        }

        return result;
    }
};