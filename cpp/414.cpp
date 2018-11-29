#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


int main() {

    int N;
    string line;
    int min, max, cur;

    string str_N;

    getline(cin, str_N);

    N = atoi(str_N.data());

    while(N != 0) {
        
        min = 23;
        vector<int> blanks;

        
        while(N--) {
            getline(cin, line);
            cur = 0;

            for(char c: line) {
                if(c == ' ')
                    cur++;
            }

            //cout << "for line " << line << "  have " << cur << " blanks" << endl; 
            blanks.push_back(cur);

            if(cur < min)
                min = cur;
       
        }

        int total = 0;
        for(int i: blanks)
            total += i - min;

        cout << total << endl;

        getline(cin, str_N);
        N = atoi(str_N.data());
    }
}