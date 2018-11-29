#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long  n, m, k, S;
    cin >> n;
    cin >> S;

    int count  = 0;
    

    

    while (S != 0) {

        if(S < n ) {
            n--;
        }
        else {
            //cout << "current S " << S << endl;
            //cout << "take max " << n << endl;
            S -= n;
            //n--;
            count++;
        }

    }

    //vector<long long> a;

    cout << count << endl;
    return 0;   
}