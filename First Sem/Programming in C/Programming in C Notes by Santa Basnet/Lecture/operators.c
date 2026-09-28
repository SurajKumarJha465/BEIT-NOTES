/* Operators demonstration program. */
#include <stdio.h>
int main()
{
    unsigned int x, y, z;
    int a = 2, b, c;
    {
        x = 7;
        y = 16;
        x &= y;
        c = ((b=2) == a);
    }
    printf("c = %d & x = %d\n", c, x);
    return(1);
}
