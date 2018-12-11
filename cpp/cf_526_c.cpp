#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long n;

    vector<long long> s;
    char cur_c;
    long long count_a = 0;
    long long ta = 0;

    while (cin >> cur_c) {
        if (cur_c == 'b') {
            if (count_a != 0) {
                s.push_back(count_a);
                count_a = 0;
            }
        }

        if (cur_c == 'a') {
            count_a++;
            ta++;
        }
    }

    if (count_a)
        s.push_back(count_a);

    if (s.empty()) {
        cout << "0";
        return 0;
    }

    if (s.size() == 1) {
        cout << s[0];
        return 0;
    }

    unsigned long long total = 1l;
    long long tmod = 1000000007;

    for (int i = 0; i < s.size(); ++i) {
        total = (total * (s[i]+1)) % tmod;
    }
    cout << total - 1;
    return 0;
}