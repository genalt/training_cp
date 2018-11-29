#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void perms(string& input, size_t pos) {
    if(pos == input.length()) {
        cout << input << endl;
    }
    else {
        for(int i = pos; i < input.length(); i++) {
            swap(input[pos], input[i]);
            perms(input, pos + 1);
            swap(input[pos], input[i]);
        }
    }
}

void subsets(string& input, size_t pos, vector<char>& subset) {
    if(pos == input.length()) {
        for(char c: subset) {
            cout << c;
        }
        cout << endl;
        return;
    }

    subset.push_back(input[pos]);
    subsets(input, pos + 1, subset);


    subset.pop_back();
    subsets(input, pos + 1, subset);


}
int main() {

    string str = "123";
    vector<char> subset;

    //perms(str, 0);

    subsets(str, 0, subset);
    return 0;
}