#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int T;

    while(cin >> T) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        int maybe_s = 1, maybe_q = 1, maybe_pq = 1;

        while(T--) {
            int op, n, real_s, real_q, real_pq;

            cin >> op >> n;

            if(op == 1) {
                s.push(n);
                q.push(n);
                pq.push(n);

                //cout << "pushing " << n << endl;
            } else {
                if(pq.empty())
                    maybe_pq = 0;
                else {
                    real_pq = pq.top(); pq.pop();
                }

                if(s.empty())
                    maybe_s = 0;
                else {
                    real_s = s.top(); s.pop();
                }

                if(q.empty())
                    maybe_q = 0;
                else {
                    real_q = q.front(); q.pop();
                }

                /*
                cout << "expecting " << n << endl;
                cout << "in pq " << real_pq << endl;
                cout << "in s "  << real_s << endl;
                cout << "in q " << real_q << endl;
                */

                if(maybe_pq && real_pq != n)
                    maybe_pq = 0;

                if(maybe_q && real_q != n)
                    maybe_q = 0;

                if(maybe_s && real_s != n)
                    maybe_s = 0;
            }
        }
        if(maybe_pq + maybe_q + maybe_s == 0) {
            cout << "impossible" << endl;
        }
        else if(maybe_pq + maybe_q + maybe_s > 1) {
            cout << "not sure" << endl;
        } else {
            if(maybe_pq)
                cout << "priority queue" << endl;

            if(maybe_s)
                cout << "stack" << endl;

            if(maybe_q)
                cout << "queue" << endl;
        }
    }
    return 0;
}