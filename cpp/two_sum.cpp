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

    vector<int> A({1, 2, 7, 8, 17});
    vector<int> B({2, 4, 5, 6, 8, 25});


    int sum = 9;


    int i = 0, j = B.size() -1; 
    while(i < A.size() && j >= 0 ) {
            
            cout << i << " " << j << endl;
            if(A[i] + B[j] > sum ) {
                j--;
            } else if (A[i] + B[j] < sum)
                i++;
            else {
                cout <<  "result = " << A[i] << "+" << B[j] << endl;
                j--;
                i++;
            }
    } 


    return 0;
}