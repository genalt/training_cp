#include <iostream>

using namespace std;

int main() {
    int w,h,k;

    cin >> w >> h >> k;
    int total = 0;
    while(k--) {

        total += (2*w + 2*h - 4);

        w -= 4;
        h -= 4;
    }

    cout << total;
    return 0;
}