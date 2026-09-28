/*Iteration using function pointer */

#include <stdio.h>

#define MAX_COLORS  256

typedef struct {
    char* name;
    int red;
    int green;
    int blue;
} Color;

Color Colors[MAX_COLORS];

void eachColor (void (*fp)(Color *c))
{
    int i;
    for (i=0; i<MAX_COLORS; i++)
        (*fp)(&Colors[i]);
}

void printColor(Color* c)
{
    if (c->name)
        printf("%s = %i,%i,%i\n", c->name, c->red, c->green, c->blue);
}

int main()
{
    Colors[0].name="red";
    Colors[0].red=255;

    Colors[1].name="blue";
    Colors[1].blue=255;

    Colors[2].name="black";

    Colors[100].name = "pink";

    eachColor(printColor);
    return(1);
}
