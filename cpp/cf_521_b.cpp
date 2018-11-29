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
    ll T = 0, n, m, a, b;
    cin >> n;
    vi flats(n, 0);
    
    for(int i = 0; i < n; i++)
        cin >> flats[i];

    
    for(int i = 1; i < n - 1; i++) {

        if(flats[i] == 0 && flats[i-1] == 1 && flats[i+1] == 1) {
            T += 1;
            flats[i+1] = 0;
        }

    }
    cout << T << endl;
    
        
    return 0;
}