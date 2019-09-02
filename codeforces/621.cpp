#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        string cur;
        cin >> cur;

        if (cur == "1" || cur == "4" || cur == "78")
            cout << '+' << endl;
        else if (cur.length() >= 2 && cur[cur.length() - 1] == '5' && cur[cur.length() - 2] == '3')
            cout << '-' << endl;
        else if (cur.length() >= 3 && cur[0] == '1' && cur[1] == '9' && cur[2] == '0')
            cout << '?' << endl;
        else if (cur[0] == '9' && cur[cur.length() - 1] == '4')
            cout << '*' << endl;

        
    }


    
}