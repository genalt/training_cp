#include <iostream>
#include <vector>

#define MAX_VALUE 200001
using namespace std;

bool can(int l, int k, const vector<long long> &d, vector<long long> &result) {
    if (l == 0) return false;
    
    for (int i = 0; i < d.size(); ++i)
        for (int j = 0; j < d[i] / l; ++j) {
            result.push_back(i);
            if (result.size() == k)
                return true;
        }
    return false;
}

int main() {
    long long n, k, tmp;
    cin >> n >> k;
    vector<long long> d(MAX_VALUE, 0);

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        d[tmp]++;
    }

    int l = 0, r = n - 1, max = 1;
    vector<long long> res;

    while (l <= r) {
        int m = (l + r) / 2;
        res.clear();

        if (can(m, k, d, res)) {
            if (m > max)
                max = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    res.clear();
    can(max, k, d, res);

    for (long long v : res)
        cout << v << " ";
    return 0;
}