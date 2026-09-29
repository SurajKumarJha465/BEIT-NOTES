/*if-else if ... else statement: Grade Calculator*/
#include<stdio.h>
int main()
{
    int x;
    printf("Enter mark of a subject :");
    scanf("%d",&x);
    if(x < 0 || x > 100) {
        printf("Invalid input !\n");
    } else if (x >= 90) {
        printf("Grade - A\n");
    }else if (x >= 80) {
        printf("Grade - B\n");
    }else if (x >= 70) {
        printf("Grade - C\n");
    }else if (x >= 60) {
        printf("Grade - D\n");
    }else {
        printf("Grade - F\n");
    }
    return(1);
}

