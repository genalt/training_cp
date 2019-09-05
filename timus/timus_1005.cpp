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


void take_stone(const vector<int>& stones, multiset<int>& taken, int i, int totalw, int *mn) {
    if(i == stones.size()) {
        int takenw1 = 0;
        int takenw2 = 0;

        for(auto j: taken)
            takenw1 += stones[j];
        takenw2 = totalw - takenw1;
        (*mn) = min(*mn, abs(takenw1 - takenw2));
    } else {
        taken.insert(i);
        take_stone(stones, taken, i+1, totalw, mn);
        taken.erase(i);
        take_stone(stones, taken, i+1, totalw, mn);
    }
}


int32_t main() {
    IOS;
    int n, mn, totalw = 0;
    cin >> n;
    vector<int> stones;
    multiset<int> taken;

    while(n--) {
        int tmp;
        cin >> tmp;
        stones.push_back(tmp);
        totalw += tmp;
    }

    mn = totalw;
    take_stone(stones, taken, 0, totalw, &mn);
    cout << mn;
    return 0;
}