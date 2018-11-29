#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {
    FenwickTree(const vector<int>& arr) {
        ft.assign(arr.size() + 1, 0);

        for(int i = 0; i < arr.size(); i++)
            add(i, arr[i]);
    }

    int rsq(int idx1, int idx2) {
        idx1++;
        idx2++;

        if(idx1 > 1)
            return rsq(idx2) - rsq(idx1 - 1);
        else
            return rsq(idx2);
    }

    void add(int idx, int value) {
        idx++;
        for(; idx < ft.size(); idx += lso(idx))
            ft[idx] += value;
    }


    private:
    
    vector<int> ft;

    int lso(int idx) {
        return idx & (-idx);
    }

    int rsq(int idx) {
        int sum = 0;
        for(; idx > 0; idx -= lso(idx))
            sum += ft[idx];
        return sum;
    }

};

int main() {
    vector<int> myv({ 2,4,5,5,6,6,6,7,7,8,9 });

    FenwickTree myft(myv);

    cout << myft.rsq(7, 8) << endl;

    myft.add(7, 6);

    cout << myft.rsq(7, 8) << endl;
    return 0;
}