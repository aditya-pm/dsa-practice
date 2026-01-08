#include <algorithm>
#include <iostream>
#include <unordered_map>

bool is_permutation(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}

bool is_permutation_better(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) return false;

    std::unordered_map<char, int> freq1;
    std::unordered_map<char, int> freq2;

    for (char ch : str1) freq1[ch]++;
    for (char ch : str2) freq2[ch]++;

    for (auto& [ch, count] : freq1) {
        if (count != freq2[ch]) return false;
    }

    return true;
}

bool is_permutation_best(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) return false;

    std::unordered_map<char, int> freq;

    for (char ch : str1) freq[ch]++;
    for (char ch : str2) freq[ch]--;

    for (auto& [ch, count] : freq)
        if (count != 0) return false;

    return true;
}

// input is assumed to be ASCII (0 - 127)
// A = 65
// a = 97
bool is_permutation_true_best(std::string str1, std::string str2) {
    if (str1.size() != str2.size()) return false;

    int freq[128] = {0};
    for (char ch : str1) freq[ch]++;
    for (char ch : str2) freq[ch]--;

    for (int count : freq)
        if (count != 0) return false;

    return true;
}