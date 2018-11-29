#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, tmp;
    int cur, costs;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    while(cin >> N) {
        if(N == 0)
            break;
        while(N--) {
            cin >> tmp;
            pq.push(tmp);
        }

        costs = 0;
        while(pq.size() != 1) {

            int f = pq.top(); pq.pop();
            int s = pq.top(); pq.pop();
            
            costs += (f + s);
            pq.push(f + s);

        }

        cout << costs << endl;
        pq.pop();
    }
    return 0;
}
