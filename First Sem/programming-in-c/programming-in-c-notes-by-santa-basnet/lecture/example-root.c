/*Print the square root of first n natural numbers*/
#include <stdio.h>
#include <math.h>
float find_root(int x){
    return(sqrt(x));
}
/* 	
*	Program entry point, completes with 0 for successful
*	operations. 
*/
int main(){
    int n, iter;
    printf("First n = ");
    scanf("%d", &n);
    for(iter = 1; iter <= n; iter++)
        printf("%4d --> %.2f\n",iter, find_root(iter));
    return(0);
}
