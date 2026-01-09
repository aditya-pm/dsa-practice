#include <iostream>

std::string compress_str(const std::string& str) {
    if (str.empty()) return "";

    std::string result;
    int count = 1;
    char current_char = str[0];

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == current_char) {
            count++;
            continue;
        } else {
            result += current_char;
            result += std::to_string(count);
            count = 1;
            current_char = str[i];
        }
    }

    result += current_char;
    result += std::to_string(count);

    if (str.size() <= result.size())
        return str;
    else
        return result;
}

int main() {
    std::cout << compress_str("aaabbb") << std::endl;
    return 0;
}