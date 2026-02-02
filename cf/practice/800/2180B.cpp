#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x;
    cin >> x;
    string result;
    string str;
    for (int i = 0; i < x; i++) {
        cin >> str;

        if (result.empty() || result + str < str + result) {
            result += str;
        } else {
            result = str + result;
        }
    }
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;  // comment this line if problem has single test case
    while (t--) {
        solve();
    }
    return 0;
}
