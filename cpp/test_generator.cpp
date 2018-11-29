#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    int N = 2000;
    int K = 0;
    cout << N << " " << K << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0;j < N; j++) {

            //rand()
            //cout << char(   rand()%26 + 'a'  ) ;
            cout << 'z' ;
        }
        cout << endl;
    }
    return 0;
}
