#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 1000000000000000
#define all(v) v.begin(), v.end()
#define rep(i, a, b) for (i = (ll)a; i < (ll)b; i++)
#define revrep(i, a, b) for (i = (ll)a; i >= (ll)b; i--)
#define ii pair<ll, ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll int
#define vi vector<ll>
ll modexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}
#define rs resize
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

const ll N = 200003;
ll i, n, a, sz, ans, r, s, curr, lo, hg, mid, p;
vi v;
map<ll, ll> mp;
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    rep(i, 0, n) {
        cin >> a;
        mp[a] += 1;
    }

    for (auto g : mp)
        v.pb(g.se);
    sort(all(v));

    sz = v.size();
    rep(i, 1, n + 1) {
        curr = -1;
        s = i;
        r = 0;
        while (1) {
            lo = curr + 1;
            hg = sz - 1;
            p = -1;
            while (lo <= hg) {
                mid = (lo + hg) / 2;
                if (v[mid] >= s) {
                    p = mid;
                    hg = mid - 1;
                } else
                    lo = mid + 1;
            }

            if (p == -1)
                break;

            r += s;
            curr = p;
            s *= 2;
        }

        ans = max(ans, r);
    }
    cout << ans;
    return 0;
}