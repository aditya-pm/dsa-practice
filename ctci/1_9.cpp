/*
CTCI 1.9

Problem:
Given two strings s1 and s2, determine if s2 is a rotation of s1.
A rotation is formed by taking a string, splitting it at some index,
and swapping the two resulting parts.

--------------------------------------------------------------------

Brute Force Approach:
Try all possible split points in s1.

For each index i:
- left  = s1[0 .. i)
- right = s1[i .. n)
- Check if right + left == s2

This explicitly generates every possible rotation of s1 and compares
it with s2.

Brute Force Complexity:
- Time:  O(n²)
  There are n split points, and each comparison builds and compares
  strings of length n.
- Space: O(n)
  Temporary strings are created during each iteration.

--------------------------------------------------------------------

Optimized Insight:
If s2 is a rotation of s1, then s2 must appear as a substring of
s1 concatenated with itself (s1 + s1).

WOrking:
Every rotation of s1 is a contiguous substring of s1 + s1.
Doubling the string implicitly encodes all possible rotations in
a single structure.

Example:
  s1 = "waterbottle"
  s2 = "erbottlewat"

  s1 + s1 = "waterbottlewaterbottle"
  s2 appears inside s1 + s1 → s2 is a rotation of s1.

Constraints:
- Rotations must have equal length
- Uses exactly one substring check (as required by CTCI)

Optimized Complexity:
- Time:  O(2n) ~ O(n)
  One string concatenation and one substring search.
- Space: O(2n) ~ O(n)
  Additional string storage for s1 + s1.
*/

#include <iostream>

// brute force
bool is_string_rotation_brute_force(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) return false;

    int n = s1.length();

    for (int i = 0; i < n; i++) {
        std::string left = s1.substr(0, i);
        std::string right = s1.substr(i, n - i);
        if (right + left == s2) {
            return true;
        }
    }

    return false;
}

// optimized
bool is_string_rotation(const std::string& s1, const std::string& s2) {
    if (s1.length() != s2.length()) return false;

    std::string s1_twice = s1 + s1;
    return (s1_twice.find(s2) != std::string::npos);
}

int main() {
    std::cout << is_string_rotation("waterbottle", "erbottlewat") << std::endl;
    return 0;
}