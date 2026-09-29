/*function pointer for arithmetic operation */

#include <stdio.h>

int add (int x, int y)
{
    return (x + y);
}

int subtract (int x, int y)
{
    return (x - y);
}

int multiply (int x, int y)
{
    return(x*y);
}

int divide (int x, int y)
{
    return(y==0?0:x/y);
}

int operation(int a, int b, int (*callOper)(int, int))
{
    return ((*callOper)(a, b));
}

int main()
{
    int  a = 100, b = 45;
    int  (*plus) (int, int) = add;
    int (*minus) (int, int) = subtract;
    int (*cross) (int, int) = multiply;
    int (*slash) (int, int) = divide;

    printf("Add = %d\n",operation(a, b, plus));
    printf("Subtract = %d\n",operation(a, b, minus));
    printf("Multiply = %d\n",operation(a, b, cross));
    printf("Divide = %d\n",operation(a, b, slash));

    return 0;
}
