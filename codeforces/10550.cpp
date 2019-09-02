#include <iostream>
using namespace std;


int main() {

    int res, start, first, second, third;
    cin >> start >> first >> second >> third;
    
    while(1) {

        if (start == 0 && first == 0 && second == 0 && third == 0)
            break;
        res = 720 + 360;
        res += (start < first) ? (40 - first + start) * 9 : (start - first) * 9;
        res +=  (first < second) ? (second - first) * 9 : (second + 40 - first) * 9;
        res += (second < third) ? (40 - third + second) * 9 : (second -third) * 9;
        cout << res << endl;
        cin >> start >> first >> second >> third;

    }
}

