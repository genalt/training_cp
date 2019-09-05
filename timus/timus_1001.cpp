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
    int n, m, k;
    vector<int> a;
    while(cin >> n) {
        a.push_back(n);
    }


    for(int i = a.size() -1; i >= 0; i--) {

        printf("%.4f\n", sqrt(a[i]));

    }
    return 0;
}