#include <set>
#include <iostream>
#include <vector>

using namespace std;


int main() {
    int T;
    multiset<int> green_army, blue_army;
    vector<int> left_green, left_blue;

    cin >> T;
    while(T--) {
        int blue, green, fields, tmp, total_green = 0, total_blue = 0;
        green_army.clear();
        blue_army.clear();
        left_green.clear();
        left_blue.clear();


        cin >> fields >> green >> blue;

        while(green--) {
            cin >> tmp;
            green_army.insert(tmp);
            total_green += tmp;
        }

        while(blue--) {
            cin >> tmp;
            blue_army.insert(tmp);
            total_blue += tmp;
        }

        if (total_blue == total_green) {
            cout << "green and blue died" << endl;
            if(T != 0)
                cout << endl;
            continue;
        }


        //cout << "start battle" << endl;

        while(!green_army.empty() && !blue_army.empty()) {

            for(int i = 0; i< fields && !green_army.empty() && !blue_army.empty(); i++) {
                auto git = green_army.end(); git--;
                auto bit = blue_army.end(); bit--;

                //cout << "field " << i <<  ":  "  << *git  << " VS " << *bit << endl;
                if(*git > *bit) {
                    left_green.push_back(*git - *bit);

                    //cout << "green left " << (*git - *bit) << endl;
                } else if (*git < *bit) {
                    left_blue.push_back(*bit - *git);

                    //cout << "blue left " << (*bit - *git) << endl;
                }

                green_army.erase(git);
                blue_army.erase(bit);
            }
            
            /*
            cout << "round finished" << endl;

            cout << "green reserve" << endl;

            for(int i: green_army)
                cout << i << endl;


            cout << "blue reserve" << endl;


            for(int i: blue_army)
                cout << i << endl;
            */

            for(int i = 0; i < left_blue.size(); i++) {
                blue_army.insert(left_blue[i]);
            }
            left_blue.clear();


            for(int i = 0; i < left_green.size(); i++) {
                green_army.insert(left_green[i]);
            }
            left_green.clear();

            /*
            cout << "green army" << endl;

            for(int i: green_army)
                cout << i << " ";

            cout << endl;


            cout << "blue army" << endl;


            for(int i: blue_army)
                cout << i << " " ;
            cout << endl;
            */

        }


        if(!blue_army.empty()) {
            cout << "blue wins" << endl;
            for(auto it =  blue_army.rbegin(); it != blue_army.rend(); it++)
                cout << *it << endl;
        } else {
            cout << "green wins" << endl;
            for(auto it =  green_army.rbegin(); it != green_army.rend(); it++)
                cout << *it << endl;
        }

        if(T != 0)
            cout << endl;

    }
    return 0;
}