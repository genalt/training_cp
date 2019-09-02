#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int T;
    int N;
    int tmp;
    int T_case = 1;
    vector<int> stations;

    cin >> T;
    while(T--) {
        cin >> N;
        stations.clear();
        
        // read available galons
        for(int i = 0; i < N; i++) {
            cin >> tmp; 
            stations.push_back(tmp);
        }
        // read how much spend
        for(int i = 0; i < N; i++) {
            cin >> tmp; 
            stations[i] -= tmp;
        }

        bool completed = false;
        int passed_st;

        for(int start_station = 0; start_station < N && !completed; ) {
            int tank = stations[start_station];
            passed_st = 0;

            int next_station = (start_station + 1) % N;

            while(tank >= 0 && passed_st < N) {
                tank += stations[next_station];
                passed_st++;
                next_station = (next_station + 1) % N;
            }

            if(passed_st == N){
                cout << "Case " << T_case << ":" " Possible from station " << (start_station + 1) << endl;
                completed = true;
            }
            
            if(next_station > start_station)
                start_station = next_station;
            else
                completed = true;
        }        

        if(passed_st != N)
            cout << "Case " << T_case << ":" " Not possible" << endl;
        T_case++;
    }
    return 0;
}