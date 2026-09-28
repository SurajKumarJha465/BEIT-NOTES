/* Calculate the value of PI */
#include<stdio.h>
#include<math.h>
int main(){
    int n, k, deno, sign;
    float pi = 0.0f;
    printf("How many terms : ");
    scanf("%d",&n);
    for(k = 0, deno = 1; k < n; k++, deno+=2){
        sign = k % 2 == 0 ? 1 : -1;
        pi += sign * (4.0/deno);
    }
    printf("\nValue of PI = %f", pi);
    return(1);
}
