/*do-while: Print first n natural numbers*/
#include <stdio.h>
int main()
{
    int n, iter;
    printf("How many : ");
    scanf("%d", &n);
    iter = 1;
    do{
         printf("%d\n",iter);
         iter++;
    }while(iter <= n);
    return(0);
}
