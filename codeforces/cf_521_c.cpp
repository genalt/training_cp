#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <unordered_map>

using namespace std;
typedef unsigned long long ll;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    ll T, n, m;

    cin >> n;

    vl a(n, 0);
    vl answer;
    vl dup(1000006, 0);
    ll total_sum = 0;

    

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        dup[a[i]]++;
        total_sum += a[i];
    }

    //cout << "total " << total_sum << endl;

    for(int i = 0; i < n; i++) {
        ll cur_sum = total_sum - a[i];

        //cout << "substr " << a[i] << " got " << cur_sum << endl;
        if(cur_sum % 2 == 1)
            continue;

        cur_sum /= 2;

        if(cur_sum > 1000000)
            continue;

        //cout << "half =  " << cur_sum << endl;
        
        if(cur_sum == a[i] && dup[a[i]] > 1) {

            //cout << "cur half is our removed but have more " << a[i] << endl;
            answer.push_back(i);
        } else if (cur_sum != a[i] && dup[cur_sum] >= 1) {

            //cout << "cur half is NOT our" << a[i] << endl;
            answer.push_back(i);
        }

    }

    cout << answer.size() << endl;

    for(ll ca: answer)
        cout << (ca + 1) << " ";

    
    return 0;
}