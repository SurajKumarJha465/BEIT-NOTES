//reflect a triangle about x-axis and y-axis using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void reflectTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int rx, int ry)
{
    int x1_new = x1 * rx;
    int y1_new = y1 * ry;
    int x2_new = x2 * rx;
    int y2_new = y2 * ry;
    int x3_new = x3 * rx;
    int y3_new = y3 * ry;
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
}
int main()
{
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 300, y3 = 100;
    int rx = 1, ry = -1;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    reflectTriangle(x1, y1, x2, y2, x3, y3, rx, ry);
    delay(5000);
    closegraph();
    return 0;
}
