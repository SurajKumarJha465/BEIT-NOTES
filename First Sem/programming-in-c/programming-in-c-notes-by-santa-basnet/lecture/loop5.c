#include <stdio.h>
int main()
{
    short n = 20, i, j;
    for(i=1;i<n;i++){
        for(j=1; j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    return(0);
}
