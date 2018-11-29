#include <iostream>
#include <set>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    string line;
    set<string> dict;
    while(getline(cin, line)) {
        string tmp = "";
        for(int i = 0; i < line.length(); i++) {
            if(isalpha(line[i])) {
                tmp += tolower(line[i]);
            } else {
                if(tmp != "")
                    dict.insert(tmp);
                tmp = "";
            }
        }

        if(tmp != "")
            dict.insert(tmp);
    }

    for(string s: dict)
        cout << s << endl;
    return 0;
}