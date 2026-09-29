#include <stdio.h>

// function implementation
int Sum(int x, int y)
{
    return(x+y);
}

// calling from main
int main()
{
    int (*sumPtr)(int, int) = Sum;
    int a1 = 10, a2 = 20;
    printf("%d\n",(*sumPtr)(a1, a2));
    return(1);
}
