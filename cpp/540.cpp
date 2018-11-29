#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);

    int T;

    int scenario = 1;
    while(cin >> T) {

        if(T == 0)
            break;
        
        map<int , int> team_mapping;
        int team_index = 1;
        int team_size;
        int tmp;

        cout << "Scenario #" << scenario << endl;
        scenario++;

        while(T--) {
            cin>> team_size;
            while(team_size--) {
                cin >> tmp;
                team_mapping[tmp] = team_index;
            }
            team_index++;
        }


        deque<queue<pair<int, int> > > team_queue;

        // read commands
        string command;
        while(cin >> command) {
            int id;
            int team_number;


            if(command == "STOP")
                break;

            if(command == "ENQUEUE") {
                cin >> id;

                
                team_number = team_mapping[id];
                //cout << "enq ID = " << id << " from team = " << team_number << endl;

                //try to find team in queue
                bool found = false;
                for(auto it = team_queue.begin(); it != team_queue.end() && !found; it++) {
                    pair<int,int> cur_team = (*it).front();
                    if(cur_team.first == team_number) {
                        (*it).push(make_pair(team_number, id));
                        found = true;
                    }
                }

                if(!found) {
                    queue<pair<int, int> > new_team;
                    new_team.push(make_pair(team_number, id));
                    team_queue.push_back(new_team);
                }
            }

            if(command == "DEQUEUE") {

                auto f = team_queue.begin();

                cout << (*f).front().second << endl;
                (*f).pop();

                if((*f).empty())
                    team_queue.pop_front();
            }
            
        }
        cout << endl;
    }
    return 0;
}