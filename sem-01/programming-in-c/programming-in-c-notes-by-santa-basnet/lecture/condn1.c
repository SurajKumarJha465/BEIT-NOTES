/*if-else statement: */
#include<stdio.h>
int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    if(x<0) {
        x = -x;
    }
    printf("The absolute value is %d.\n",x);
    return(1);
}
