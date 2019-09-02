#include <iostream>
#include <vector>

using namespace std;


bool helper(vector<int>& a, vector<int>& b, vector<int>& t, int n, int i) {

    //cout << "I = " << i << endl;
    if(t.size() == n)
        return true;
    
    bool is_done = false;
    for(int j = 0; j <= 3 && !is_done; j++) {
        
        if(a[i] == (t[i]|j) && b[i] == (t[i]&j) ) {
            t.push_back(j);
            is_done = helper(a, b, t, n, i+1);
            if(!is_done) {
                t.pop_back();
            }
        }
        /*
        else {
            cout << "J " << j << "not valid for t[i] " << t[i] << " a & b = " << a[i] << " " << b[i] << endl;
        }
        */
    }

    return is_done;
}

int main() {

    int n, tmp;
    vector<int> a;
    vector<int> b;
    vector<int> t;

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        cin >> tmp;
        a.push_back(tmp);

    }

    for(int i = 0; i < n - 1; i++) {
        cin >> tmp;
        b.push_back(tmp);

    }

    bool res = false;

    for(int i = 0; i <= 3 && !res; i++) {
        t.push_back(i);
        res = helper(a, b, t, n, 0);
        if(!res)
            t.pop_back();
    }

    if(res) {
        cout << "YES" << endl;
        for(int i: t)
            cout << i << " ";
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    
    return 0;
}