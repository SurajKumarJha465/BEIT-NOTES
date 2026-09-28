//bresenham's circle drawing algorithm
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
void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int pk = 1 - r;
    drawCircle(xc, yc, x, y);
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
        drawCircle(xc, yc, x, y);
    }
}
int main()
{
    int xc = 50, yc = 50, r = 30;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    bresenhamCircle(xc, yc, r);
    delay(5000);
    closegraph();
    return 0;
}