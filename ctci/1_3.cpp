#include <iostream>

std::string URLify(std::string str, int length) {
    std::string result;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ')
            result += "%20";
        else
            result += str[i];
    }
    return result;
}

// CTCI mentions string contains sufficient space at the end to hold the additional chars.
void URLify_inplace(std::string& str, int length) {
    int space_count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') space_count++;
    }

    int final_length = length + space_count * 2;  // str.length();
    int ptr1 = length - 1;
    int ptr2 = final_length - 1;

    while (ptr1 >= 0) {
        if (str[ptr1] != ' ') {
            str[ptr2] = str[ptr1];
            ptr2--;
        } else {
            str[ptr2] = '0';
            str[ptr2 - 1] = '2';
            str[ptr2 - 2] = '%';
            ptr2 -= 3;
        }
        ptr1--;
    }
}

int main() {
    std::string str = "Mr John Smith      ";
    URLify_inplace(str, 13);
    std::cout << str << std::endl;

    std::cout << URLify("Mr John Smith", 13);

    return 0;
}
