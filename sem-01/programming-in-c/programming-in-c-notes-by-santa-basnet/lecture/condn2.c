/*if-else statement: Odd or Even Number*/
#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    if(x % 2 == 0) {
        printf("%d is even.\n",x);
    } else {
        printf("%d is odd.\n",x);
    }
    return(1);
}
