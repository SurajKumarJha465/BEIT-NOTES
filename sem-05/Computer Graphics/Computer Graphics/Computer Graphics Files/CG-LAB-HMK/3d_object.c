//render a 3d object using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void draw3dObject(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
    line(x5, y5, x6, y6);
    line(x6, y6, x7, y7);
    line(x7, y7, x8, y8);
    line(x8, y8, x5, y5);
    line(x1, y1, x5, y5);
    line(x2, y2, x6, y6);
    line(x3, y3, x7, y7);
    line(x4, y4, x8, y8);
}
void render3dObject(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5, int x6, int y6, int x7, int y7, int x8, int y8, int tx, int ty, int tz)
{
    int x1_new = x1 + tx;
    int y1_new = y1 + ty;
    int x2_new = x2 + tx;
    int y2_new = y2 + ty;
    int x3_new = x3 + tx;
    int y3_new = y3 + ty;
    int x4_new = x4 + tx;
    int y4_new = y4 + ty;
    int x5_new = x5 + tx;
    int y5_new = y5 + ty;
    int x6_new = x6 + tx;
    int y6_new = y6 + ty;
    int x7_new = x7 + tx;
    int y7_new = y7 + ty;
    int x8_new = x8 + tx;
    int y8_new = y8 + ty;
    draw3dObject(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, x4_new, y4_new, x5_new, y5_new, x6_new, y6_new, x7_new, y7_new, x8_new, y8_new);
}
int main()
{
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 200, y3 = 200, x4 = 100, y4 = 200;
    int x5 = 150, y5 = 50, x6 = 250, y6 = 50, x7 = 250, y7 = 150, x8 = 150, y8 = 150;
    int tx = 50, ty = 50, tz = 50;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    draw3dObject(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8);
    render3dObject(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, tx, ty, tz);
    delay(5000);
    closegraph();
    return 0;
}
