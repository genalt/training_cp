#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int three_sum_closest(vector<int> &A, int B) {

    if(A.size() < 3) return 0;
    
    sort(A.begin(), A.end());
    
    int top_closest;
    int top_sum;

    for(int i = 0; i < A.size() - 2; i++ ) {
        
        int j = i + 1;
        int k = A.size() - 1;

        int cur_sum = A[j] + A[k] + A[i];
        int cur_closest = abs(cur_sum - B);
       
        while(j < k) {
            
            if( abs(A[j] + A[k] + A[i] - B) < cur_closest) {
                cur_closest = abs(A[j] + A[k] + A[i] -B);
                cur_sum = A[j] + A[k] + A[i];
            }

            if(A[j] + A[k] + A[i] > B) {
                k--;    
            } else if (A[j] + A[k] + A[i] < B) {
                j++;
            } else {
               return A[i] + A[j] + A[k];
            }
        }

        if(cur_closest < top_closest || i == 0) {
            top_closest = cur_closest;
            top_sum = cur_sum;
        }

    }
      
    return top_sum;

}



int main() {
    vector<int> A({-1, 2, 1, -4});
    int sum = -8;

    cout <<  three_sum_closest(A, sum) << endl;

    return 0;
}