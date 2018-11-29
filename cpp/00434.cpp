#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    int size;
    vector<int> right;
    vector<int> front;
    int r_heights[9];
    int f_heights[9];

    int min_b, max_b, tmp;
    
    cin >> T;
    while(T--) {

        cin >> size;
        right.clear();
        front.clear();
        
        for(int i = 0; i <= 9; i++)
            r_heights[i] = f_heights[i] = 0;


        // read front
        for(int i=0; i<size; i++){
            cin >> tmp;
            front.push_back(tmp);
        }

        // read right
        for(int i=0; i<size; i++){
            cin >> tmp;
            right.push_back(tmp);
        }

        min_b = max_b = 0;

        

        //count min
        for(int i = 0; i < size; i++) {
            r_heights[right[i]]++;
            f_heights[front[i]]++;
        }
        
        for(int i = 0; i <= 9; i++) {
            min_b += std::max(r_heights[i], f_heights[i])*i;
        }

        //cout << "Min = " << min_b << endl;
        for(int i = 0; i <= 9; i++)
            r_heights[i] = f_heights[i] = 0;

        
        //evaluate max
        for(int i = 0; i < size; i++) {
            for(int j=1; j <= front[i]; j++)
                f_heights[j]++;
        }

        for(int i = 0; i < size; i++){
            for(int j=1; j <= right[i]; j++)
                max_b += f_heights[j];
        }            
        cout << "Matty needs at least " << min_b << " blocks, and can add at most " << (max_b - min_b) << " extra blocks." << endl;
    }

}