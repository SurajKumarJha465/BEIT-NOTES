/*switch - example: An arithmetic operator*/
#include <stdio.h>
int main()
{
    int x, y; char op;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Enter operator (+, -, *, /) : ");
    scanf(" %c",&op);
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", x, y, x+y);
            break;
        case '-':
            printf("%d - %d = %d\n", x, y, x-y);
            break;
        case '*':
            printf("%d * %d = %d\n", x, y, x*y);
            break;
        case '/':
            if(y == 0){
                printf("Undefined !\n");
            }else{
                printf("%d + %d = %d", x, y, x/y);
            }
            break;
        default:
            printf("Invalid operator !\n");
        }
}
