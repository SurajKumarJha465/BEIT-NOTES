#include<stdio.h>

int main() {
    int a = 0, b = 0, *p;
    a = 10;
    p = &a;
    *p = 20;
    printf("a = %d, b = %d\n", a, b);

    p = &b;
    *p = 10;
    printf("a = %d, b = %d\n", a, b);

    a = *p;
    printf("a = %d, b = %d\n", a, b);
    return 0;
}
