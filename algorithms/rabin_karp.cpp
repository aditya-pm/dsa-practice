#include <iostream>
#include <string>
using namespace std;

#define d 256  // number of characters

void rabinKarp(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();
    int i, j;

    int p = 0;  // hash for pattern
    int t = 0;  // hash for text
    int h = 1;

    // h = pow(d, m-1) % q
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // initial hash values
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // slide pattern over text
    for (i = 0; i <= n - m; i++) {
        // if hash matches
        if (p == t) {
            // check characters
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        // compute next hash
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int q = 101;  // prime number

    rabinKarp(text, pattern, q);
}