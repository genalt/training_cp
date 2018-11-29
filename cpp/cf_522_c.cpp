#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<bool> dp[6];

    for (int i = 1; i < 6; i++) {
        dp[i].assign(n, false);
        dp[i][0] = true; // can start with any
    }
    for (int i = 0; i < n; i++)
        cin >> a[i];


    for (int c = 1; c < n; ++c) {
        if (a[c] < a[c - 1]) { // go down
            for (int l = 5; l > 0; --l) {
                if (dp[l][c - 1]) {
                    if (l == 1) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    for (int m = l - 1; m > 0; --m)
                        dp[m][c] = true;
                    break;
                }
            }
        } else if (a[c] == a[c - 1]) {
            for (int l = 5; l > 0; --l) {
                dp[l][c] = true;
            }
        } else {
            for (int l = 1; l < 6; ++l) {
                if (dp[l][c - 1]) {
                    if (l == 5) {
                        cout << "-1" << endl;
                        return 0;
                    }
                    for (int m = l + 1; m < 6; ++m)
                        dp[m][c] = true;
                    break;
                }
            }
        }
    }

    bool go_down;
    int prev = -1;

    for (int i = 0; i < n; i++) {

        if (i != 0 && a[i] > a[i - 1]) {
            go_down = false;
            if (i != n - 1 && a[i] > a[i + 1]) { // local max
                prev = 5;
            } else {
                for (int j = 1; j < 6; j++) {
                    if (dp[j][i] && j > prev) {
                        prev = j;
                        break;
                    }
                }
            }
        } else if (i != 0 && a[i] < a[i - 1]) {
            go_down = true;
            if (i != n - 1 && a[i] < a[i + 1]) { // local min
                prev = 1;
            } else {
                for (int j = 5; j > 0; --j) {
                    if (dp[j][i] && j < prev) {
                        prev = j;
                        break;
                    }
                }
            }
        } else {
            if (i == n - 1 || a[i] == a[i + 1]) {
                if (prev != 4) prev = 4;
                else           prev = 3;
            } else if (a[i] < a[i + 1]) {
                go_down = false;
                if (prev != 1) prev = 1;
                else           prev = 2;
            } else if (a[i] > a[i + 1]) {
                go_down = true;
                if (prev != 5) prev = 5;
                else           prev = 4;
            }
        }

        cout << prev << " ";
    }
    return 0;
}