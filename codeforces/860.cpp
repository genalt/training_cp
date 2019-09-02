#include <map>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;


vector<string> tokenizer(string text, string delimeters) {
    vector<string> tokens;

    string cur = "";
    for(int i = 0; i < text.length(); i++) {
        auto ptr = delimeters.find(text[i]);

        if(ptr == string::npos){
            cur += tolower(text[i]);
        }
        else {
            if(cur != "")
                tokens.push_back(cur);
            cur = "";
        }
    }
    if(cur != "")
        tokens.push_back(cur);
    return tokens;
}


int main() {
    
    string word;
    double Et = 0.0;
    double Erel = 0.0;
    double Emax = 0.0;
    int L = 0;

    map<string, int> freqs;

    //cout << "before loop" << endl;
    while(getline(cin, word)) {

        
        if(word == "****END_OF_INPUT****")
            break;

        if(word == "****END_OF_TEXT****") {

            Emax = log10(L);
            double freq_sum = 0;
            for(auto f: freqs) {
                freq_sum += f.second * (Emax - log10(f.second));
            }

            
            Et = freq_sum / L;

            Erel = (Et / Emax) * 100;
            printf("%d %.1lf %.02f\n", L, Et, Erel);

            //cout << "Et: " << Et << " Emax: " << Emax << " Erel " << Erel << endl;

            Et = Erel = Emax = 0.0;
            L = 0;
            freqs.clear();
        }
        else {

            vector<string> toks = tokenizer(word, " ,.:;!?\"()\t");


            L+= toks.size();
            
            
            for(string c_word: toks) {
                //cout << "A word " << c_word << endl;
                auto ptr = freqs.find(c_word);
                if(ptr != freqs.end())
                    freqs[c_word]++;
                else {
                    freqs[c_word] = 1;
                }
            }


        }

    }

    return 0;
}