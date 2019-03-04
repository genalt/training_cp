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
#include <stack>

#define mp make_pair
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

void merge(stack<pair<bool, bool>>& wall) {
    bool was_merged = true;
    while(wall.size() > 1 && was_merged) {
        pair<bool, bool> br2 = wall.top(); wall.pop();
        pair<bool, bool> br1 = wall.top(); wall.pop();
        pair<bool, bool> new_b;
        was_merged = false;

        // if both are odd in height
        if(br1.first && br2.first) {
            new_b = mp(true, (br1.second + br2.second) % 2);
            was_merged = true;
        } else if (!br1.first && !br2.first) { // both are even in height
            new_b = mp(false, (br1.second + br2.second) % 2);
            was_merged = true;
        } else {
            if(!br1.second) {
                was_merged = true;
                new_b = mp(br2.first, (br1.second + br2.second) % 2);
            } else if (!br2.second) {
                was_merged = true;
                new_b = mp(br1.first, (br1.second + br2.second) % 2);
            }
        }

        if(was_merged) {
            wall.push(new_b);
        } else {
            wall.push(br1);
            wall.push(br2);
        }
    }
}


int32_t main() {
    IOS;
    int n, ai;
    cin >> n;

    stack<pair<bool, bool>> wall;

    for(int i = 0; i < n; i++) {
        cin >> ai;
        wall.push(mp(ai%2, 1));
        merge(wall);
    }


    if(wall.size() == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}