#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <deque>

#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int32_t main() {
    IOS;
    unsigned int n;
    const int MOD=1e9+7;

    cin >> n;
    vi a(n + 1, 0), dp(n+1, 0);

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    dp[0] = dp[1] = 1;

    for(int i = 2; i <= n; ++i) {
        vi delim;

        for(int j = 1; j*j <= a[i]; j++) {
            if(a[i] % j == 0){
                delim.pb(j);
                if(j != a[i]/j)
                    delim.pb(a[i]/j);
            }
        }
        sort(delim.begin(), delim.end());

        for(int j = delim.size() - 1; j >= 0; --j) {
            int d = delim[j];
            if(d <= n) {
                dp[d] += dp[d-1];
                dp[d] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <=n; i++){
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}