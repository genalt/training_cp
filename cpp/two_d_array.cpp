#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {

    
    int W;
    int H;
    int N = 2;
    bool **array;


    while(N-- ){
        cin >> W >> H;
        array = (bool **) malloc(W * sizeof(bool *));

        for(int i = 0; i< W; i++)
            array[i] = (bool *) malloc(H * sizeof(bool));

        
        for(int i = 0; i < W; i++)
            free(array[i]);

        free(array);
    }
        
    return 0;
}