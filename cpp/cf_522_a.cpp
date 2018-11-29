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
    ll T, n, m, k, b;
    cin >> n >> k;

    int diff_sets = 0;

    vi a(n);
    vector<int> num(101, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];

        
        num[a[i]]++;
        if(num[a[i]] == 1)
            diff_sets++; 
    }

    int max = 0;
    //int total = n;

    

    for(int i =0; i <=100; i++) {

        if(num[i]) {
            if(num[i] % k != 0) {
                int rest = num[i] % k;
                //total += rest;
                num[i] += (k - rest);
            }
        }

        if(num[i] > max) {
            max = num[i];
            //cout << "new max N " << i << " value " << num[i] << endl; 
        }
    }


    int dishes = max / k;

    if(max % k != 0)
        dishes++;

//    cout << "dishes " << dishes << endl;
//    cout << "sets " << diff_sets << endl;

    cout << diff_sets * k * dishes  - n << endl;
    return 0;
}