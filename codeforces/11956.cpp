#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main() {

    int T;
    cin >> T;

    int test_n = 1;
    while(T--) {
        cout << "Case " << test_n << ": ";

        string commands;
        cin >> commands;

        vector<int> led_mem(100, 0);
        int pointer = 0;

        for(char ch: commands) {
            switch(ch) {
                case '.':
                    break;
                case '+':
                    led_mem[pointer]++;
                    break;
                case '-':
                   led_mem[pointer]--;
                    break;
                case '>':
                    pointer++;
                    break;
                case '<':
                    pointer--;
                    break;
            }
            led_mem[pointer] = (led_mem[pointer] + 256) % 256;
            pointer = (pointer + 100) % 100;
        }

        for(int i = 0; i < led_mem.size(); i++) {
            int m = led_mem[i];
            ostringstream hd;
            hd << setfill('0') << setw(2) << hex << m;
            
            string hds = hd.str();
            transform(hds.begin(), hds.end(), hds.begin(), [](unsigned char c){ return std::toupper(c);});

            cout << hds;
            if(i != led_mem.size() - 1)
                cout << " ";
        }
        cout << endl;
        test_n++;
    }

}