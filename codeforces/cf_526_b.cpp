#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define make_pair mp
#define push_back pb
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n, s, min_v = 1000000001;

    cin >> n >> s;

    vector<long long> a(n + 1);

    long long total = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        total += a[i];
        if (a[i] < min_v)
            min_v = a[i];
    }

    if (total < s) {
        cout << "-1";
        return 0;
    }

    if (total == s) {
        cout << "0";
        return 0;
    }

    long long taken = 0;
    for (int i = 1; i <= n; ++i) {
        taken += a[i] - min_v;

        if (taken >= s) {
            cout << min_v;
            return 0;
        }
    }

    s -= taken;

    if (s / n > 0) {
        min_v -= s / n;
    }

    if (s % n == 0) {
        cout << min_v;
    } else {
        cout << min_v - 1;
    }

    return 0;
}