#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
    int c, s, set = 1;
    while (cin >> c >> s)
    {
        cout << "Set #" << set << endl;
        vector<int> spic(s);

        int total_mass = 0;
        for (int i = 0; i < s; i++)
        {
            cin >> spic[i];
            total_mass += spic[i];
        }

        for (int i = spic.size(); i < 2 * c; i++)
            spic.push_back(0);

        sort(spic.begin(), spic.end());

        double AM = (double)total_mass / c;
        double IMB = 0;

        for (int i = 0; i <= (spic.size() - 1) / 2; i++)
        {
            cout << " " << i << ":";
            if (spic[i]) cout << " " << spic[i];
            if (spic[spic.size() - 1 - i]) cout << " " << spic[spic.size() - 1 - i];
            IMB += abs(spic[i] + spic[spic.size() - 1 - i] - AM);
            cout << endl;
        }

        printf("IMBALANCE = %.5f\n\n", IMB);
        set++;
    }
    return 0;
}