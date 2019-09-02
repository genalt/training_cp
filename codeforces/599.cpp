#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<string> tokenizer(string text, string delims) {
    string cur = "";
    vector<string> tokens;

    for(int i = 0; i < text.length(); ++i) {
        auto ptr = delims.find(text[i]);
        if(ptr != string::npos) {
            if(cur != "") {
                tokens.push_back(cur);
                cur = "";
            }
        } else {
            cur += text[i];
        }
    }

    if(cur != "")
        tokens.push_back(cur);
    return tokens;
}

int main() {
    int T;
    cin >> T;

    bool G[26][26];
    bool checked[26];

    while(T--) {
        for(int i = 0; i < 26; i ++) {
            checked[i] = false;
            for(int j = 0; j < 26; j++)
                G[i][j] = false;
        }

        string input;
        while(cin >> input) {
             if(input[0] == '*')
                break; // end of edges;

            vector<string> edge = tokenizer(input, "(),");
            G[edge[0][0] - 'A'][edge[1][0] - 'A'] = true;
            G[edge[1][0] - 'A'][edge[0][0] - 'A'] = true;
        }

        cin >> input;
        vector<string> vertices = tokenizer(input, ",");

        queue<int> starts;
        for(int i = 0; i <  vertices.size(); i++)
            starts.push(vertices[i][0] - 'A');

        int trees = 0, acorns = 0, size_cc;

        // BFS
        while(!starts.empty()) {
            int cur_start = starts.front(); starts.pop();
            if(checked[cur_start])
                continue;
            size_cc = 1;
            checked[cur_start] = true;

            queue<int> cur_cc;
            cur_cc.push(cur_start);

            while(!cur_cc.empty()) {
                int tmp_v = cur_cc.front(); cur_cc.pop();
                for(int i = 0; i < 26; i ++) {
                    if(G[tmp_v][i] && !checked[i]) {
                        size_cc++;
                        cur_cc.push(i);
                        checked[i] = true;
                    }
                }
            }
            if(size_cc == 1)
                acorns++;
            else    
                trees++;
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;
    }
    return 0;
}