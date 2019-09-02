#include <cctype>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


void tokenize(const string& line, const string& delimeters, vector<string>&  tokens){
    int start = 0, end;
    while( (end = line.find_first_of(delimeters, start)) != string::npos) {
        if(start < end)
            tokens.push_back(line.substr(start, end - start));
       start = end + 1;
    }
    if(start != line.length())
         tokens.push_back(line.substr(start));
}


int main() {
    string line = "dfadf f asdffas,23   ";

    string delimeters = " ,";

    vector<string> tokens;

    tokenize(line, delimeters, tokens);


    for(auto s: tokens)
        cout << s << endl;
}
