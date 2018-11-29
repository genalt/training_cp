#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    ios::sync_with_stdio(false);

    int T;
    string line;
    getline(cin, line);
    T = stoi(line);

    while(T--) {

        int P;
        getline(cin, line);
        P = stoi(line);

        vector<int> nbs;

        int  min_nb = P;  // max number of neighbors for current place

        for(int i = 1; i <= P; i++) {
            getline(cin, line);
            int cur_nb = 1; 
            
            for(int j = 0; j < line.length(); j++) {
                if(line[j] == ' ')
                    cur_nb++;
            }
            if(cur_nb <= min_nb) {
                nbs.push_back(cur_nb);
                nbs.push_back(i);
                min_nb = cur_nb;
            }
        }

        bool first = true;
        for(int i = 0; i < nbs.size(); i +=2) {
            if(nbs[i] == min_nb) {
                if(!first)
                    cout << " ";
                cout << nbs[i + 1];
                first = false;
            }
        }

        cout << endl;
        getline(cin, line);
    }
    return 0;
}