#include <cstdio>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

int main() {
    int n = -1, e = 0, i = 0, t = 0, c;
    while( (c = getchar()) != EOF) {
        if(c == 'n') n++;
        if(c == 'e') e++;
        if(c == 'i') i++;
        if(c == 't') t++;
    }
    n/=2, e/=3;
    printf("%d\n", MIN( MIN(n,e), MIN(i,t)));
}