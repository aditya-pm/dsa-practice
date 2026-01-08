#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isAnagram_sort(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool isAnagram_map(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> freq1;
        std::unordered_map<char, int> freq2;

        for (char ch : s) freq1[ch]++;
        for (char ch : t) freq2[ch]++;

        for (auto& [ch, count] : freq1) {
            if (count != freq2[ch]) return false;
        }

        return true;
    }

    bool isAnagram_map_optimized(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        for (char c : t) freq[c]--;

        for (auto& [ch, count] : freq)
            if (count != 0) return false;

        return true;
    }

    // input is said to be lower case alphabets
    bool isAnagram_array(string s, string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int count : freq)
            if (count != 0) return false;

        return true;
    }
};