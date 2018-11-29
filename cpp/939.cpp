#include <map>
#include <vector>
#include <iostream>
#include <string>


using namespace std;

int main() {

    int T;
    string word1, word2;
    map<string, string> genes;
    map<string, vector<string> > parents;
    cin >> T;

    // read all data
    while(T--) {
        cin >> word1 >> word2;
        // if name of child
        if(word2 != "recessive" && word2 != "non-existent" && word2 != "dominant") {

            map<string, vector<string> >::iterator it = parents.find(word2);
            if(it != parents.end())
                it->second.push_back(word1);
            else {
                vector<string> p;
                p.push_back(word1);
                parents.insert(make_pair(word2, p));
            }
        }
        else {
            genes[word1] = word2;
        }
    }

    typedef map<string, vector<string> >::iterator pit;

    pit it = parents.begin();

    while(!parents.empty()) {

        if (it == parents.end())
            it = parents.begin();

        string name = it->first;

        string parent1 = it->second[0];
        string parent2 = it->second[1];


        auto gene1_it = genes.find(parent1);
        auto gene2_it = genes.find(parent2);
        
        if(gene1_it == genes.end() || gene2_it == genes.end()) {
            it++;
            continue;
        }

        string gene1 = genes[parent1];
        string gene2 = genes[parent2];

        if( (gene1 == "dominant" && gene2 == "dominant") || (gene1 == "recessive" && gene2 == "dominant") || 
            (gene1 == "dominant" && gene2 == "recessive")) {
                genes[name] = "dominant";
            }
        else if ((gene1 == "non-existent" && gene2 == "non-existent") || (gene1 == "non-existent" && gene2 == "recessive") ||
        (gene1 == "recessive" && gene2 == "non-existent")) {
            genes[name] = "non-existent";

        } else {
            genes[name] = "recessive";
        }

        parents.erase(it);
        it++;
    }

    for(auto it: genes) {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}