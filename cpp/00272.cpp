// TEX Quotes (replace all double quotes to TEX() style quotes)

#include <stdio.h>

int main(){

    char c;
    int in_quote = 0;

    while(scanf("%c", &c) != EOF) {

        if (c == '"') {
            in_quote && printf("''");
            !in_quote && printf("``");
            in_quote = 1 - in_quote;
            continue;
        }

        printf("%c", c);

    }
    return 0;
}