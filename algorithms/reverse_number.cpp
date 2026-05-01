#include <iostream>
using namespace std;

int reverse_number(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    cout << reverse_number(123) << endl;
    return 0;
}
