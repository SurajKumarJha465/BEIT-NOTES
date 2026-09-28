//scale a triangle by scaling factor sx and sy using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void scaleTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy)
{
    int x1_new = x1 * sx;
    int y1_new = y1 * sy;
    int x2_new = x2 * sx;
    int y2_new = y2 * sy;
    int x3_new = x3 * sx;
    int y3_new = y3 * sy;
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
}
int main()
{
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 300, y3 = 100;
    int sx = 2, sy = 2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    scaleTriangle(x1, y1, x2, y2, x3, y3, sx, sy);
    delay(5000);
    closegraph();
    return 0;
}   