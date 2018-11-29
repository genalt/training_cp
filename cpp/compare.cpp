#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool helper(vector<int> a, vector<int> b, int start_a, int start_b) {
    int i =start_a, j = start_b;
    while(i != a.size() && j != b.size()) {
        if(a[i] > b[j])
            return true;
        if(a[i] < b[j])
            return false;

        i++;
        j++;
    }
    if(i == a.size() && j == b.size())
        return true;

    if(i == a.size()) {
        return helper(a, b, start_a, j);
    }

    if(j == b.size()) {
        return helper(a, b, i, start_b);
    }
}

bool compare_digits(const int &a, const int &b) {
    vector<int> a_digits;
    vector<int> b_digits;

    int a_mut = a;
    int b_mut = b;

    while(a_mut/10) {
        a_digits.push_back(a_mut % 10);
        a_mut /= 10;
    }
    a_digits.push_back(a_mut);

    while(b_mut/10) {
        b_digits.push_back(b_mut % 10);
        b_mut /= 10;
    }
    b_digits.push_back(b_mut);

    reverse(a_digits.begin(), a_digits.end());
    reverse(b_digits.begin(), b_digits.end());

    return helper(a_digits, b_digits, 0, 0); 
}

int main() {

    vector<int> myv({ 2,4,5,5,6,6,6,7,91,8,9 });
    sort(myv.begin(), myv.end(), compare_digits);

    for(int i: myv)
        cout << i;
    cout << endl;
    return 0;

}
