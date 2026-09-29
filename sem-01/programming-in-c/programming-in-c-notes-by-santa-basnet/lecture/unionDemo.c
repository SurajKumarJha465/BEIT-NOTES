//Union Demo

#include <stdio.h>
#include <stdlib.h>

union Data{
    int x;
    double y;
    char ch;
};

int main(){
    printf("%d\n",sizeof(union Data));
    return 0;
}
