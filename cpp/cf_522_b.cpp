#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);
    ll T, n, m, a, b;
    
    string handle;

    cin >> handle;


    int rows = (int) handle.length() / 20;

    if(handle.length() % 20 != 0)
        rows++;

    //cout << "rows " << rows << endl;

    //cout << "size " << handle.length() << endl;

    int cols = (int) handle.length() / rows;

    if(handle.length() % rows != 0)
        cols++;

    int stars  = rows * cols - handle.length();

    int star_row = stars / rows;

    int left = stars -  rows*star_row;

    cout << rows << " " << cols << endl;
    
    //cout << "size " << handle.length() << endl;

    //cout << "total stars " << stars << " then left " << left << endl;
    
    //return 0;

    int pos  = 0;
    for(int i = 0; i < rows; i++) {

        int j = 0;
        if(i < left) {
            cout << '*';
            j++;
        }

        for(; j < cols; j++) {
            
            if(j < star_row)
                cout << '*';
            else {
                cout << handle[pos];
                pos++;
            }

        }
        cout << endl;
    }


    return 0;
}