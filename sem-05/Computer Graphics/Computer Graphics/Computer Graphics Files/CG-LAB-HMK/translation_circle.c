//translate a circle by translation factor tx and ty using graphics.h
//put new circle with color red
//draw circle by circle function
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
    putpixel(xc+y, yc+x, RED);
    putpixel(xc-y, yc+x, RED);
    putpixel(xc+y, yc-x, RED);
    putpixel(xc-y, yc-x, RED);
}
void translateCircle(int xc, int yc, int r, int tx, int ty)
{
    int x = 0, y = r;
    int pk = 1 - r;
    drawCircle(xc+tx, yc+ty, x, y);
    while (y >= x)
    {
        x++;
        if (pk >= 0)
        {
            y--;
            pk = pk + 2*x - 2*y + 1;
        }
        else
            pk = pk + 2*x + 1;
        drawCircle(xc+tx, yc+ty, x, y);
    }
}
int main()
{
    int xc = 50, yc = 50, r = 30;
    int tx = 50, ty = 50;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    bresenhamCircle(xc, yc, r);
    translateCircle(xc, yc, r, tx, ty);
    delay(5000);
    closegraph();
    return 0;
}

