#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string line;
    int case_n = 1;
    while(cin >> line) {

        vector<int> sums;
        cout << "Case " << case_n << ":" << endl;

        for(int i = 0; i< line.length(); i++) {
            if(i == 0) {
                sums.push_back(line[i] - '0');
            }
            else {
                sums.push_back(sums[i-1] + (line[i] - '0'));
            }
        }


        int tests;
        cin >> tests;
        while(tests--) {
            int i, j;
            cin >> i >> j;
                
            int min_i = min(i, j);
            int max_i = max(i, j);

            if(line[min_i] == '0' && line[max_i] == '0' && sums[min_i] == sums[max_i]) {
                cout << "Yes" << endl;
                continue;
            }

            if(line[min_i] == '1' && line[max_i] == '1' && (sums[max_i] - sums[min_i]) == (max_i - min_i)){
                cout << "Yes" << endl;
                continue;
            }
            
            cout << "No" << endl;

        }

        case_n++;
    }
}