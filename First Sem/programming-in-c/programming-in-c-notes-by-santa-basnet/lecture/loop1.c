/*while - example: Print first n natural numbers*/
#include <stdio.h>
int main()
{
    int n, iter;
    printf("How many : ");
    scanf("%d", &n);
    iter = 1;
    while(iter <= n){
        printf("%d\n",iter);
        iter++;
    }
    return(0);
}
