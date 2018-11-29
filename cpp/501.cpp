#include <set>
#include <vector>
#include <iostream>

using namespace std;

int main() {

    int T;
    cin >> T;

    while(T--) {
        int M;
        int N;
        int tmp;
        cin >> M >> N;
        vector<int> elems;
        vector<int> reqs;

        while(M--) {
            cin >> tmp;
            elems.push_back(tmp);
        }
        while(N--) {
            cin >> tmp;
            reqs.push_back(tmp);
        }

        multiset<int> db;

        db.insert(elems[0]);
        int elem_index = 1;
        multiset<int>::iterator it = db.begin();

        bool first = true;

        for(int i = 0; i< reqs.size() ; ) {
            if(reqs[i] == db.size()) {
                if(first) {
                    cout << *it << endl;
                    first = false;
                }
                else {
                    it++; // next value of output
                    cout << *it << endl;
                }
                i++;  // request completed, next request
            } else { // start fill DB
                db.insert(elems[elem_index]);
                if(elems[elem_index] < *it)
                    it--;
                elem_index++;
            }
        }

        if(T != 0)
            cout << endl;
    }
    return 0;
}