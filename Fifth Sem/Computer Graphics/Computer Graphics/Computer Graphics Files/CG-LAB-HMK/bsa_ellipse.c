//bresenham's ellipse drawing algorithm for TURBOC3
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawEllipse(int xc, int yc, int x, int y)
{
    putpixel(xc+x, yc+y, RED);
    putpixel(xc-x, yc+y, RED);
    putpixel(xc+x, yc-y, RED);
    putpixel(xc-x, yc-y, RED);
}
void bresenhamEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0, y = ry;
    int rx2 = rx*rx, ry2 = ry*ry;
    int px = 0, py = 2*rx2*y;
    drawEllipse(xc, yc, x, y);
    int p;
    p = ry2 - (rx2*ry) + (0.25*rx2);
    while (px < py)
    {
        x++;
        px = px + 2*ry2;
        if (p < 0)
            p = p + ry2 + px;
        else
        {
            y--;
            py = py - 2*rx2;
            p = p + ry2 + px - py;
        }
        drawEllipse(xc, yc, x, y);
    }
    p = ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2;
    while (y > 0)
    {
        y--;
        py = py - 2*rx2;
        if (p > 0)
            p = p + rx2 - py;
        else
        {
            x++;
            px = px + 2*ry2;
            p = p + rx2 - py + px;
        }
        drawEllipse(xc, yc, x, y);
    }
}
int main()
{
    int xc = 50, yc = 50, rx = 30, ry = 20;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    bresenhamEllipse(xc, yc, rx, ry);
    delay(5000);
    closegraph();
    return 0;
}
