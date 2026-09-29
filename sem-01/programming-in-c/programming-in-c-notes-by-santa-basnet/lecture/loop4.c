/*for: Infinite loop but stops*/
#include <stdio.h>
int main()
{
    short n = 10, i;
    for(i = 1; i < n; i--) {
        printf("%d\n", i);
    }
    return(0);
}
