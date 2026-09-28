/*Swapping values of the variables*/
#include <stdio.h>
int main(){
    int x = 99, y = 11;
    x = x + y; /* x = 110, y = 11 */
    y = x - y; /* x = 110, y = 99 */
    x = x - y; /* x = 11, y = 99 */
    printf("x = %d, y = %d", x, y);
    return(1);
}
