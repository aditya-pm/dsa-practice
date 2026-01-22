#include <iostream>
#include <vector>

std::vector<int> string_match(const std::string& text, const std::string& pattern) {
    std::vector<int> indices;

    int n = text.size();
    int m = pattern.size();

    if (m == 0 || m > n) return indices;

    // only iterate while match is possible
    for (int i = 0; i <= n - m; i++) {
        int j = 0;

        while (j < m && text[i + j] == pattern[j]) j++;

        if (j == m) indices.push_back(i);
    }

    return indices;
}

int main() {
    std::string s1 = "Hello World! Hello Everyone";
    std::string s2 = "ello";

    std::vector<int> indices = string_match(s1, s2);

    for (int index : indices) std::cout << index << " ";
    std::cout << std::endl;

    return 0;
}
