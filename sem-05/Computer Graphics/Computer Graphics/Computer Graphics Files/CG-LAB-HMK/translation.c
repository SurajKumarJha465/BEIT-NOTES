//translate a triangle by translation factor tx and ty using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void translateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
    int x1_new = x1 + tx;
    int y1_new = y1 + ty;
    int x2_new = x2 + tx;
    int y2_new = y2 + ty;
    int x3_new = x3 + tx;
    int y3_new = y3 + ty;
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
}
int main()
{
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 300, y3 = 100;
    int tx = 50, ty = 50;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    translateTriangle(x1, y1, x2, y2, x3, y3, tx, ty);
    delay(5000);
    closegraph();
    return 0;
}
