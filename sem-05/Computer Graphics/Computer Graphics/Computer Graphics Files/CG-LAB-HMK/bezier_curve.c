// bezier curve implementation using graphics.h
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawBezierCurve(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3)
{
    int x, y;
    for (double t = 0.0; t <= 1.0; t += 0.0001)
    {
        x = pow(1-t, 3)*x0 + 3*t*pow(1-t, 2)*x1 + 3*pow(t, 2)*(1-t)*x2 + pow(t, 3)*x3;
        y = pow(1-t, 3)*y0 + 3*t*pow(1-t, 2)*y1 + 3*pow(t, 2)*(1-t)*y2 + pow(t, 3)*y3;
        putpixel(x, y, RED);
    }
}
int main()
{
    int x0 = 50, y0 = 50, x1 = 150, y1 = 100, x2 = 200, y2 = 200, x3 = 300, y3 = 300;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawBezierCurve(x0, y0, x1, y1, x2, y2, x3, y3);
    delay(5000);
    closegraph();
    return 0;
}

