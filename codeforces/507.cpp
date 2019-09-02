#include <iostream>
#include <vector>

using namespace std;

pair<int, int> kadanes(vector<int> v) {
    int max_sum, max_start, max_end, cur_sum, cur_start, cur_end;

    cur_sum = max_sum = v[0];
    max_start = max_end = cur_start = cur_end = 0;

    for(int i = 1; i < v.size(); i ++) {
        if(cur_sum + v[i] >= v[i]) {
            cur_sum += v[i];
            cur_end = i;
        } else {
            cur_sum = v[i];
            cur_start = cur_end = i;
        }

        if(cur_sum > max_sum ||
            (cur_sum == max_sum && cur_end - cur_start > max_end - max_start)) {
            max_sum = cur_sum;
            max_start = cur_start;
            max_end = cur_end;
        }
    }

    return make_pair(max_start, max_end);
}

int main() {
    ios::sync_with_stdio(false);
    int T,route = 1;
    cin >> T;
    
    while(T--) {
        int stops;
        cin >> stops;
        vector<int> v(stops - 1);

        bool was_positive = false;
        for(int i = 0; i < v.size(); i++) {
            cin >> v[i];
            if(v[i] > 0) was_positive = true;
        }

        if(!was_positive) {
            cout << "Route " << route << " has no nice parts" << endl;
            route++;
            continue;
        }

        pair<int, int> answer = kadanes(v);
        answer.first++;
        answer.second+=2;

        cout << "The nicest part of route " << route << " is between stops " << answer.first << " and " << answer.second << endl;
        route++;
    }
    return 0;
}