#include <iostream>
#include <vector>
using namespace std;

#define R(a) find(a)
#define FRIENDS(a, b) (R(a) == R(b))
#define ENEMIES(a, b) (R(a) == e[R(b)])
#define NOBODY -1

vector<int> p, e; // parents and enemies (Disjoint Sets)

int find(int a) {
    return (p[a] == a) ? a : (p[a] = find(p[a]));
}

void join(int a, int b) {
    p[R(a)] = R(b);
}

void set_friends(int a, int b) {
    if(e[R(a)] != NOBODY && e[R(b)] != NOBODY) {
        join(e[R(a)], e[R(b)]);   // join enemy sets first
        int ne = R(e[R(a)]);
        join(a, b);               // join frined sets
        e[R(a)] = ne;
        e[ne] = R(a);
    } else {
        int oe = max(e[R(a)], e[R(b)]);  // has only one enemy set OR none
        join(a, b);
        e[R(a)] = oe;
        if(oe != NOBODY) e[oe] = R(a);
    } 
}

void set_enemies(int a, int b) {
    int pa = R(a), pb = R(b);
    if(e[pb] != NOBODY) join(a, e[pb]);
    if(e[pa] != NOBODY) join(b, e[pa]);
    e[R(a)] = R(b);
    e[R(b)] = R(a);
}

int main() {
    int N, op, a, b;
    cin >> N;

    for (int i = 0; i < N; i++)  // init root with itself
        p.push_back(i);
    e.assign(N, NOBODY); // init enemies of every root
    
    while (cin >> op >> a >> b) {
        if(op == 1) {
            if(ENEMIES(a, b)) cout << "-1" << endl;
            else             set_friends(a, b);
        }
        if(op == 2) {
            if(FRIENDS(a, b)) cout << "-1" << endl;
            else              set_enemies(a, b);
        }
        if(op == 3) {
            if(FRIENDS(a, b)) cout << "1" << endl;
            else              cout << "0" << endl;
        }
        if(op == 4) { 
            if(ENEMIES(a, b)) cout << "1" << endl;
            else              cout << "0" << endl;
        }
    }
    return 0;
}
