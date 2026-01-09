#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

bool is_one_edit_away(const std::string& s1, const std::string& s2) {
    int len1 = s1.size();
    int len2 = s2.size();

    if (std::abs(len1 - len2) > 1) return false;

    const std::string& shorter = (len1 < len2) ? s1 : s2;
    const std::string& longer = (len1 < len2) ? s2 : s1;

    int i = 0;  // pointer for shorter
    int j = 0;  // pointer for longer
    bool used_edit = false;

    while (i < shorter.size() && j < longer.size()) {
        if (shorter[i] == longer[j]) {
            i++;
            j++;
        } else {
            if (used_edit) return false;

            used_edit = true;

            // if same length → replacement
            if (shorter.size() == longer.size()) {
                i++;
            }
            // if different length → insertion/deletion
            j++;
        }
    }

    return true;
}

int main() {
    std::cout << is_one_edit_away("pale", "ple") << std::endl;
    std::cout << is_one_edit_away("pales", "pale") << std::endl;
    std::cout << is_one_edit_away("pale", "bale") << std::endl;
    std::cout << is_one_edit_away("pale", "bake") << std::endl;

    return 0;
}