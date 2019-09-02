#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main() {

    int W, H, N;
    int x1, y1, x2, y2;
    bool **array;
    cin >> W >> H >> N;

    while(W != 0) {
        
        //array = (bool **) malloc(W * sizeof(bool *));

        array = new bool*[W];

        for(int i = 0; i< W; i++)
            //array[i] = (bool *) malloc(H * sizeof(bool));
            array[i] = new bool[H];

        for(int i = 0; i < W; i++)
            for(int j = 0; j < H; j++)
                array[i][j] = true;


        
        while(N--) {
            
            cin >> x1 >> y1 >> x2 >> y2;

            for(int i = min(x1 - 1, x2 - 1); i < max(x1, x2); i++)
                for(int j = min(y1 - 1, y2 -1); j < max(y1, y2); j++)
                    array[i][j] = false;
        }  

        int empty = 0;

        for(int i = 0; i < W; i++)
            for(int j = 0; j < H; j++)
                if(array[i][j])
                    empty++;

        if(empty == 0)
            cout << "There is no empty spots." << endl;
        else if (empty == 1)
            cout << "There is one empty spot." << endl;

        else
            cout << "There are " << empty << " empty spots." << endl;


        for(int i = 0; i < W; i++)
            delete [] array[i];
        delete [] array;

        cin >> W >> H >> N;
        
    }
    return 0;
}