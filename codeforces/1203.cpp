#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string next;
    vector<pair<int, int> > events;

    while(cin >> next) {

        int id, period, n;
        if(next == "Register") {
            cin >> id >> period;

            events.push_back(make_pair(period, id));
        } else if (next == "#") {
            int number_output;
            cin >> number_output;
            

            sort(events.begin(), events.end());
            
            int secs = 1;
            vector<int> current_events;

            for(int ready = 0; ready < number_output; secs++) {
                
                //cout << "seconds " << secs << endl;
                for(auto e: events) {
                    if( secs % e.first == 0) {
                        current_events.push_back(e.second);
                    }

                }

                sort(current_events.begin(), current_events.end());
                for(int i = 0; i < current_events.size() && ready < number_output; i++, ready++){
                    cout << current_events[i] << endl;
                }

                current_events.clear();

            }
        }

    }
    return 0;
}