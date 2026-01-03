#include <algorithm>
#include <iostream>
#include <set>
#include <string>

bool is_unique(std::string str) {
    std::set<char> seen;
    for (char ch : str) {
        if (seen.count(ch)) return false;
        seen.insert(ch);
    }
    return true;
}

bool is_unique2(std::string str) {
    int size = str.length();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (str[i] == str[j]) return false;
        }
    }
    return true;
}

bool is_unique3(std::string str) {
    std::sort(str.begin(), str.end());
    for (size_t i = 1; i < str.size(); i++) {
        if (str[i] == str[i - 1]) return false;
    }
    return true;
}

int main() {
    std::cout << is_unique("ABCA") << std::endl;

    return 0;
}
