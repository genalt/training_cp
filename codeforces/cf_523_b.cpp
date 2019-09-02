#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long  n, m;
    cin >> n >> m;

    if(n == 1) {
        cout << "0";
        return 0;
    } 

    vector<long long> a(n, 0);
    long long sum = 0, taken = 1, height = 1;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a. end());

    for(int i = 1; i < a.size() - 1; ++i) {
        taken++;
        if(a[i] > height)
            height++;
    }

    if(a[n - 1] == height) {
        taken += 1;
    }  else {
        taken += a[n-1] - height;
    }

    cout << sum - taken;
    return 0;
}