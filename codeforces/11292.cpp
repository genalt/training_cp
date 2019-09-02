#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    int n,m;

    while(cin >> n >> m) {
        if(n == 0 && m == 0) break;

        vector<int> heads(n);
        for(int i = 0; i < n; i++) cin >> heads[i];

        vector<int> knights(m);
        for(int i = 0; i < m; i++) cin >> knights[i];

        sort(heads.begin(), heads.end());
        sort(knights.begin(), knights.end());

        int sum = 0, i = 0, j = 0;
        while(i < n && j < m) {

            if(knights[j] >= heads[i]) {
                sum += knights[j];
                j++;
                i++;
            } else {
                j++;
            }
        }

        if(i == n) cout << sum << endl;
        else   cout << "Loowater is doomed!" << endl;
    }
    return 0;
}