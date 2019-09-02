#include <iostream>
#include <iomanip>
#include <ctype.h>

using namespace std;

int sum_of_digit(int number) {
    int sum = 0;
    while(number/10 > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum + number;
}


int main(){
    string name1, name2;
    while(getline(cin,name1)) {
        getline(cin,name2);

        for(char & ch: name1) ch = tolower(ch);
        for(char & ch: name2) ch = tolower(ch);

        int sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < name1.length(); i++)
            if(name1[i] >= 'a' && name1[i] <= 'z')
                sum1 = sum1 + (name1[i] - 'a') + 1;

        for(int i = 0; i < name2.length(); i++)
            if(name2[i] >= 'a' && name2[i] <= 'z')
                sum2 = sum2 + name2[i] - 'a' + 1;

        while(sum1 / 10 > 0)
            sum1 = sum_of_digit(sum1);

        while(sum2 / 10 > 0)
            sum2 = sum_of_digit(sum2);

        cout << fixed << showpoint << setprecision(2) << (double) min(sum1, sum2) / max(sum1, sum2) * 100 << " %" << endl;
    }

    return 0;
}