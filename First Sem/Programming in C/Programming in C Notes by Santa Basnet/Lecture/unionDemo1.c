//Union Demo

#include <stdio.h>

typedef enum {
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
}Days;

typedef union{
    int d;
    double dbl;
    char ch;
}Vars;

int main(){
    Vars x;
    Days myDay = WEDNESDAY;
    printf("Enum Size : %d\n", sizeof(myDay));

    return 0;
}
