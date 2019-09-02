#include <iostream>
using namespace std;


int num_of_digit(int num) {
    int len = 1;
    while(num /= 10)
        len++;
    return len;
}
int main() {
    string x0;

    cin >> x0;


    while(x0 != "END") {

        if (x0 == "1") {
            cout << "1" << endl;
            cin >> x0;
            continue;
        }


        int i = 1, cur, next;
        
        cur   = x0.length();
        next  = num_of_digit(cur);

        while(next != cur) {
            cur = next;
            next  = num_of_digit(cur);
            i++;
        }

        cout << i + 1 << endl;
        cin >> x0;
    }

    

}