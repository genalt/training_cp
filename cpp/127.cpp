#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
    ios::sync_with_stdio(false);


    string cur_pile, prev_pile;

    vector<stack<string> > stacks;

    

    while( cin >> cur_pile ) {
        if(cur_pile == "#")
            break;

        else {
            stacks.clear();
            stacks.assign(52, stack<string>());

            stacks[0].push(cur_pile);
            //read 51 piles more
            for(int i = 1; i < stacks.size(); i++) {
                cin >> cur_pile;
                stacks[i].push(cur_pile);
            }

            bool was_move = true;
            //int termin = 1000000;
            while(was_move) {

                
                int i = 1;
                
                while(was_move) {

                    was_move = false;

                    if(i - 3 >= 0) {
                        cur_pile = stacks[i].top();
                        prev_pile = stacks[i - 3].top();

                        //cout << "cur = " << cur_pile << " prev = " << prev_pile << endl;

                        if(cur_pile[0] == prev_pile[0] || cur_pile[1] == prev_pile[1]) {
                            was_move = true;
                            stacks[i].pop();
                            stacks[i - 3].push(cur_pile);

                            if(stacks[i].empty())
                                stacks.erase(stacks.begin()  + i);
                               
                            i -= 3;
                            continue;
                        }
                    }

                    if(i - 1 >= 0) {

                        cur_pile = stacks[i].top();
                        prev_pile = stacks[i - 1].top();

                        //cout << "cur = " << cur_pile << " prev = " << prev_pile << endl;

                        if(cur_pile[0] == prev_pile[0] || cur_pile[1] == prev_pile[1]) {
                            was_move = true;
                            stacks[i].pop();
                            stacks[i - 1].push(cur_pile);

                            if(stacks[i].empty())
                                stacks.erase(stacks.begin()  + i);
                            i--;
                            continue;
                        }
                    }

                    if(!was_move && i != stacks.size() - 1) {
                        was_move = true;
                        i++;
                    }
                }

                
            }

            cout << stacks.size();
            if(stacks.size() == 1)
                cout << " pile";
            else
                cout << " piles";
            cout << " remaining: ";


            for(int i = 0; i < stacks.size(); i++) {
                cout << stacks[i].size();
                if(i != stacks.size() - 1)
                    cout << " ";
                //else    
                //    cout << "!";
            }

            cout << endl;

        }
    }
    return 0;
}