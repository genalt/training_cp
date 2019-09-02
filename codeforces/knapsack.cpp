#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int knapsack(const vector<int>& w, int mw, set<int>& taken) {
    int dp[w.size() + 1][mw + 1];
    bool path[w.size() + 1][mw + 1];

    for (int i = 0; i <= w.size(); i++) {
        for (int j = 0; j <= mw; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                path[i][j] = false;
            } else {
                if (j - w[i - 1] >= 0) {
                    if (dp[i - 1][j - w[i - 1]] + w[i - 1] > dp[i - 1][j])
                        path[i][j] = true;
                    else
                        path[i][j] = false;

                    dp[i][j] = max(dp[i - 1][j - w[i - 1]] + w[i - 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                    path[i][j] = false;
                }
            }
        }
    }

    for (int i = w.size(), j = mw; i > 0 && j > 0; i--) {
        if (path[i][j]) {
            taken.insert(w[i - 1]);
            j -= w[i - 1];
        }
    }
    return dp[w.size()][mw];
}

int main() {
    vector<int> w({2, 4, 7, 15, 16});
    set<int> s;
    int mw = 30;
    int total = knapsack(w, mw, s);
    cout << total << endl;
    cout << " = " << endl;
    for (int i : s)
        cout << i << endl;
    return 0;
}
