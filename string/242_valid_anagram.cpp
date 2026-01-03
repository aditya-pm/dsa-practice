#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }

    bool isAnagramV2(string s, string t) {
        unordered_map<char, int> seen;
    }
};