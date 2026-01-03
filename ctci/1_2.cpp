#include <algorithm>
#include <iostream>

bool is_permutation(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    return str1 == str2;
}