// 387. First Unique Character in a String
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (char ch : s) {
            count[ch]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    };

    int firstUniqChar2(string s) {
        int count[26] = {0};
        for (char ch : s) {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }

    int firstUniqChar3(string s) {
        unordered_map<char, int> count;
        // front of queue is the first unique char
        // queue element  = <char, indexOfChar>
        queue<pair<char, int>> q;

        for (int i = 0; i < s.size(); i++) {
            count[s[i]]++;
            q.push({s[i], i});

            // remove non-unique chars from the front
            while (!q.empty() && count[q.front().first] > 1) {
                q.pop();
            }
        }

        return q.empty() ? -1 : q.front().second;
    }
};

int main() {
    Solution s;
    cout << s.firstUniqChar2("leetcode") << endl;
    cout << s.firstUniqChar2("loveleetcode") << endl;
    cout << s.firstUniqChar2("aabb") << endl;
    return 0;
}
