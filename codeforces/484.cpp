#include <map>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> values;
    map<int, int> freqs;

    int cur_val;

    while(cin >> cur_val) {

        auto ptr = freqs.find(cur_val);

        if(ptr != freqs.end()) {
            freqs[cur_val]++;
        }
        else {
            values.push_back(cur_val);
            freqs[cur_val] = 1;
        }
    }


    for(int v: values) {

        cout << v << " " << freqs[v] << endl;

    }
    return 0;
}