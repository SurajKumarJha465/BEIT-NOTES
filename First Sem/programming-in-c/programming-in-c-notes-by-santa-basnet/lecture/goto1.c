/*goto - An example.*/
#include <stdio.h>
int main()
{
    int count = 0, x;
    for(x = 0;x<100; x++){

        //if(x % 2!= 0)
            continue;

        printf("%d\n", x);
        count ++;
        //if(count == 10)
        //break;
    }









    /*int k, x = 20;
    for(k = 1; k<=100; k++){
        printf("%d * %d = %d\n",k, x, (k*x));
        if(k == 10) goto pend;
    }
    pend:
        printf("I am jumped !\n");
        */


}
