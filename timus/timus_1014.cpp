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
    int n;
    cin >> n;

    vector<int> digits;

    if(n == 0) {
        cout << "10";
        return 0;
    }

    if(n == 1) {
        cout << "1";
        return 0;
    }


    while(n > 9) {
        bool found_next = false;
        for(int dl = 9; dl >=2; dl--) {
            if(n%dl == 0) {
                found_next = true;
                digits.push_back(dl);
                n /= dl;
                break;
            }
        }

        if(!found_next) {
            cout << "-1";
            return 0;
        }
    }

    if(n != 1)
        digits.push_back(n);
    sort(digits.begin(), digits.end());

    for(auto d: digits)
        cout << d;
    return 0;
}