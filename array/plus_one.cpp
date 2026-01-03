// 66. Plus One

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            // case 1: digit < 9, increment current digit and stop
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // case 2: digit = 9, set to zero and carry
            digits[i] = 0;
        }

        // case 3: all digits were nine
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> vec1 = {9, 9};
    vector<int> result = sol.plusOne(vec1);

    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
