#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

#define make_pair mp
#define push_back pb
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n, m;
    
    cin >> n;

    

    vector<long long> a(n+1);



    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long min_total = 10000000;


    for(int x = 1; x <= n ; ++x) {
        long long  total = 0;
        
        for(int i = 1; i <= n; ++i) {
            long long cur = (abs(x - i) + abs(i - 1) + abs(1 - x) + abs(x - 1) + abs(1 - i) + abs(i - x))   * a[i];
            total += cur;
            //cout << a[i] << endl;
            //cout << "cur for i " << i << " " << cur << endl;

        }

        if(total < min_total)
            min_total = total;

        

    }


    
    


    cout << min_total;

    return 0;
}