#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool isAnagram(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        int freq[26] = {0};

        for (char ch : s1) freq[ch - 'a']++;
        for (char ch : s2) freq[ch - 'a']--;

        for (int count : freq)
            if (count != 0) return false;

        return true;
    }

   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        for (string str : strs) {
            bool foundGroup = false;
            for (vector<string>& group : groups) {
                if (isAnagram(str, group[0])) {
                    group.push_back(str);
                    foundGroup = true;
                    break;
                }
            }
            if (!foundGroup)
                groups.push_back({str});
        }

        return groups;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> groups;

        for (string str : strs)
            map[getKey(str)].push_back(str);

        for (const auto& [_, group] : map)
            groups.push_back(group);

        return groups;
    }

    string getKey(const string& str) {
        string key = "";
        int freq[26] = {0};
        for (char ch : str) freq[ch - 'a']++;
        for (int count : freq) key += "#" + to_string(count);
        return key;
    }

    vector<vector<string>> groupAnagrams3(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string, vector<string>> map;

        for (string str : strs) {
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            map[str_copy].push_back(str);
        }

        for (const auto& [_, group] : map)
            groups.push_back(group);

        return groups;
    }
};
