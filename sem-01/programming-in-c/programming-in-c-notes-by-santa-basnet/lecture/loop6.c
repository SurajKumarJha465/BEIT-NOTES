/*continue: Number Division*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch = 'y';
    float x, y;
    while(ch == 'y' || ch == 'Y'){
        system("cls");
        printf("Enter two numbers: ");
        scanf("%f%f",&x,&y);
        if(y == 0) continue;
        printf("X/Y = %6.2f\n",(x/y));
        printf("Do you want to continue (y|Y) : ");
        scanf(" %c",&ch);
    }
}
