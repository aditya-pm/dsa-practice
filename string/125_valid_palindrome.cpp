#include <cctype>
#include <string>
using namespace std;

class Solution {
   public:
    bool isPalindrome(string& s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            // skip invalid characters on the left
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // skip invalid characters on the right
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // now both are valid, compare
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

    bool isPalindromeSyntaxCorrected(const std::string& s) {
        // NOTE:
        // std::isalnum and std::tolower are inherited from C.
        // They expect the argument to be either EOF or representable
        // as unsigned char. Passing plain `char` can cause undefined
        // behavior on some platforms, so we cast explicitly.

        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            // skip invalid characters on the left
            while (left < right &&
                   !std::isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }

            // skip invalid characters on the right
            while (left < right &&
                   !std::isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            // now both are valid, compare
            if (std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};
