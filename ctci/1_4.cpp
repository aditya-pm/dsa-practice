#include <cctype>
#include <iostream>
#include <unordered_map>

bool is_permutation_palindrome(std::string str) {
    int str_size = 0;
    for (char ch : str)
        if (isalpha(ch)) str_size++;

    bool allow_odd_count = false;
    if (str_size % 2 != 0) allow_odd_count = true;

    std::unordered_map<char, int> freq;
    for (char ch : str) {
        if (!isalpha(ch)) continue;
        freq[tolower(ch)]++;
    }

    bool found_odd = false;
    for (auto& [ch, count] : freq) {
        if (allow_odd_count && !found_odd && count % 2 != 0) {
            found_odd = true;
            continue;
        }

        if (count % 2 != 0) return false;
    }

    return true;
}

// For any permutation of a string to form a palindrome:
// - All characters must have even frequency
// - At most one character may have an odd frequency (the middle character in odd-length palindromes)
