#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct ST {
    vector<int> st[10000], lg;

    ST(vector<int> v) {
        lg.assign(v.size() + 1, 0);
        lg[2] = 1;
        for(int i = 3; i <= v.size(); i++)
            lg[i] = lg[i/2] + 1;
        
        for(int f = 0; f <= lg[v.size()]; f++) {
            st[f].assign(v.size(), 0);
            for(int i = 0; i + (1<<f) <= v.size(); i++)
                if(f == 0)  st[f][i] = v[i];
                else        st[f][i] = max(st[f-1][i],  st[f-1][i + (1<<f)/2]);
        }
    }
    int get_max(int i, int j) {
        int f = lg[j - i + 1];
        return max(st[f][i], st[f][j - (1<<f) + 1]);
    }
};


int main() {
    vector<int> test({-8, 16, 14, 8, -16});

    ST myst(test);

    cout << myst.get_max(1, 3);
}