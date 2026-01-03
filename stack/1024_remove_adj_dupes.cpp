// 1024. Remove All Adjacent Duplicates In String

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
   public:
    string removeDuplicates(string s) {
        stack<char> st;
        string result;

        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    // better (use a string itself like a stack)
    string removeDuplicates2(string s) {
        string result;
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();
            } else {
                result.push_back(c);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates2(s) << endl;  // expected: ca

    return 0;
}