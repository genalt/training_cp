#include <stdio.h>

void fun(int *a, int n) {
    for (int i = 0; i < n; i++)
        (*(a + i))++;

    for (int i = 0; i < n; i++)
        printf("%d\n", *(a + i));
}