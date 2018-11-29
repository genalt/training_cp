#include <iostream>
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

    vector<int> a;
    int tmp;
    cin >> tmp;

    int cur_case = 1;
    while(tmp != -1) {

        if(cur_case != 1)
            cout << endl;

        a.clear();
        a.push_back(tmp);
        while(tmp != -1) {
            cin >> tmp;
            a.push_back(tmp);
        }
        vector<int> dp(a.size(), 1);

        for(int i = 1; i < dp.size(); i++) {

            int cur_max  = 0;

            for(int j = i - 1; j >= 0; j--)
                if(a[j] >= a[i])
                    if(dp[j] > cur_max)
                        cur_max = dp[j];

            dp[i] = cur_max + 1;
        }

        int total_max = 0;
        for(int i = 0; i < dp.size(); i++)
            if(dp[i] > total_max)
                total_max = dp[i];

        cout << "Test #" << cur_case << ":" << endl;
        cout << "  maximum possible interceptions: " << total_max - 1 << endl;
        cur_case++;
        cin >> tmp;
    }
    return 0;
}