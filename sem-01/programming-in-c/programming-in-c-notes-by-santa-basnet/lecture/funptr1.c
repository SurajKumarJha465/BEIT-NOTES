#include <stdio.h>

// function implementation
int Sum(int x, int y)
{
    return(x+y);
}

int twiceSum(int (*sumPtr)(int, int), int a, int b)
{
    return(Sum((*sumPtr)(a, b), Sum(a, b)));
}
// calling from main
int main()
{
    int (*sPtr)(int, int) = Sum;
    int a1 = 10, a2 = 20;
    int x = twiceSum(Sum, a1, a2);
    printf("%d\n",x);
    return(1);
}
