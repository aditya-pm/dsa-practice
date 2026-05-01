#include <cmath>
#include <iostream>
using namespace std;

/*
Time Complexity: O(log n)

Explanation:
- In each iteration, we divide the number by 10.
- This effectively removes one digit from the number.
- So, the number of iterations = number of digits in n.

If n has d digits:
    d = floor(log10(n)) + 1

Therefore, the loop runs ~ log10(n) times.

Hence, time complexity = O(log n)
*/
int count_digits(int num) {
    if (num == 0) return 1;

    int digit_count = 0;
    while (num != 0) {
        num /= 10;
        digit_count++;
    }
    return digit_count;
}

/*
Time Complexity: O(1)

Explanation:
- log10(num) is a built-in mathematical function.
- It does not depend on the size of input in terms of iterations.
- It executes in constant time (hardware-level floating point operation).

Note:
- This is faster in theory, but involves floating point computation.
- Needs special handling for num = 0 since log10(0) is undefined.
*/
int count_digits_alternate(int num) {
    if (num == 0) return 1;
    return log10(num) + 1;
}

int main() {
    cout << count_digits(4389) << endl;
    cout << count_digits_alternate(4389) << endl;
    return 0;
}