//Union Demo

#include <stdio.h>

typedef enum {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
}Days;

int main(){
    Days myDay = SATURDAY;
    printf("Enum Size : %d\n", sizeof(myDay));
    printf("Value : %d\n", myDay);

    return 0;
}
