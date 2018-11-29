#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while(T--) {
        int m,c,k, tmp;
        cin >> m >> c;

        vector<vector<int> > garmets(c, vector<int>());
        for(int i = 0; i < c; i++) {
            cin >> k;
            while(k--) {
                cin >> tmp;
                garmets[i].push_back(tmp);
            }
        }
        set<int> first, second;

        for(int i = 0; i < garmets[0].size(); i++) {
            if(m - garmets[0][i] >= 0)
                first.insert(m - garmets[0][i]);
        }

        for(int i = 1; i < c; i++) {
            set<int> *cur, *next;

            if(!first.empty()) {
                cur = &first;
                next = &second;
            } else {
                next = &first;
                cur = &second;
            }

            for(auto p = cur->begin(); p != cur->end(); p++) {
                
                for(int j = 0; j < garmets[i].size(); j++) {
                    if(*p - garmets[i][j] >= 0)
                        next->insert(*p - garmets[i][j]);
                }
            }
            cur->clear();
        }

        if(first.empty() && second.empty())
            cout << "no solution" << endl;
        else if(!first.empty())
            cout << m - *first.begin() << endl;
        else
            cout << m - *second.begin() << endl;

    }
    return 0;
}