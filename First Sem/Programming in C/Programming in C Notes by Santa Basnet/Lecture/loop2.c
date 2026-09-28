/*for - example: Print first n natural numbers*/
#include <stdio.h>
int main()
{
    int n, iter;
    printf("How many : ");
    scanf("%d", &n);
    for(iter = 1; iter <= n; iter++){
        printf("%d\n",iter);
    }
    return(0);
}
