#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    ll T, n, m, a, b, k;

    cin >> T;
    while(T--) {
        cin >> a >> b >> k;
        ll pos = 0;

        if (k%2 == 1) {
            pos += a;
        }
        pos += (k/2)*a;
        pos -= (k/2)*b;

        cout << pos << endl;
    }
    

    return 0;
}