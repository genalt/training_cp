#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    vector<ll> a_c;
    vector<ll> b_c;
    ll a,b;
    cin >> a >> b;
    
    ll x = (ll)sqrt(a + b);

    //cout << "FIrst X " <<  x << endl;

    
    if(x * (x + 1) / 2 > (a + b)) {

        while(x * (x + 1) / 2 > (a + b))
            x--;

        
    }  else {

        while(x * (x + 1) / 2 <= (a + b))
            x++;
        x--;

    }



    for(int i = x; i >= 1; i--) {

        if(i <= a) {
            a_c.push_back(i);
            a -= i;
        } else {
            b_c.push_back(i);
        }

    }

    cout << a_c.size() << endl;

    if(!a_c.empty()) {
        for(int i: a_c)
            cout << i<< " ";
        cout << endl;
    }

    cout << b_c.size() << endl;
    if(!b_c.empty()) {
        for(int i: b_c)
            cout << i<< " ";
        cout << endl;
    }

    return 0;
}