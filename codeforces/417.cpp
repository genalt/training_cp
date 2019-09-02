#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;


struct str_compare {
    bool operator() (const string& lhs, const string& rhs) {
        
        if( (lhs.length() < rhs.length()) ||  (lhs.length()==rhs.length() && lhs < rhs) )
            return true;
        return false;
    }
};

void words_generator(set<string, str_compare>& words, int cur_letter, string& cur_word) {
        
        if(cur_word.length() == 5 || cur_letter > 122) {

            if(cur_word == "")
                return;

            bool valid = true;
            for(int i = 1; i < cur_word.length() && valid; i++) {
                if(cur_word[i] <= cur_word[i-1])
                    valid = false;
            }
            if(valid) {
                words.insert(cur_word);
            }
            return;
        }

        words_generator(words, cur_letter+1, cur_word);

        cur_word += cur_letter;
        words_generator(words, cur_letter+1, cur_word);
        cur_word.erase(cur_word.length()-1, 1);
}


int main() {
    
    set<string, str_compare> words;
    map<string, int> indexed_words;
    string cur = "";

    words_generator(words, 'a', cur);

    int cur_index = 1;
    for(auto w: words) {
        indexed_words[w] = cur_index;
        cur_index++;
        
    }

    while(cin >> cur) {
        auto p = indexed_words.find(cur);

        if(p == indexed_words.end())
            cout << 0 << endl;
        else
            cout << p->second << endl;
    }

    return 0;
}