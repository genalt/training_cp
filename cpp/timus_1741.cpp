#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Update {
    int v1;
    int v2;
    int size;
    int type;

    bool operator < (const Update& another) const {
        return this->v1 < another.v1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> lic_upd(n + 1, -1);
    vector<ll> pirate_upd(n + 1, -1);
    lic_upd[1] = pirate_upd[1] = 0;

    vector<Update> all_updates(m);
    int x,y,d;
    string s;
    while(m--) {
        cin >> x >> y >> d >> s;

        Update cur_upd;
        cur_upd.v1 = x;
        cur_upd.v2 = y;
        cur_upd.size = d;

        if(s == "Licensed")  cur_upd.type = 0;
        if(s == "Cracked")   cur_upd.type = 1;
        if(s == "Pirated")   cur_upd.type = 2;

        all_updates.push_back(cur_upd);
    }

    sort(all_updates.begin(), all_updates.end());

    for(Update u: all_updates) {
        if(u.type == 0) { // licensed
            if(lic_upd[u.v1] != -1 && 
                (lic_upd[u.v1] + u.size < lic_upd[u.v2] || lic_upd[u.v2] == -1))
                lic_upd[u.v2] = lic_upd[u.v1] + u.size;
        }

        if(u.type == 2) { // pirated
            if(pirate_upd[u.v1] != -1 && 
               (pirate_upd[u.v1] + u.size < pirate_upd[u.v2] || pirate_upd[u.v2] == -1))
                pirate_upd[u.v2] = pirate_upd[u.v1] + u.size;

            if(lic_upd[u.v1] != -1 && 
               (lic_upd[u.v1] + u.size < pirate_upd[u.v2] || pirate_upd[u.v2] == -1))
                pirate_upd[u.v2] = lic_upd[u.v1] + u.size;
        }

        if(u.type == 1) { //cracked 
            if(lic_upd[u.v1] != -1 && 
               (lic_upd[u.v1] + u.size < lic_upd[u.v2] || lic_upd[u.v2] == -1))
                lic_upd[u.v2] = lic_upd[u.v1] + u.size;

            if(pirate_upd[u.v1] != -1 && 
               (pirate_upd[u.v1] + u.size < pirate_upd[u.v2] || pirate_upd[u.v2] == -1))
                pirate_upd[u.v2] = pirate_upd[u.v1] + u.size;
        }
    }

    if( pirate_upd[n] == -1 && lic_upd[n] == -1)
        cout << "Offline" << endl;
    else {
        cout << "Online" << endl;
        if(pirate_upd[n] == -1)
            cout << lic_upd[n] << endl;
        else if ( lic_upd[n] == -1)
            cout <<  pirate_upd[n] << endl;
        else
            cout << min( pirate_upd[n], lic_upd[n]) << endl;
    }

    return 0;
}