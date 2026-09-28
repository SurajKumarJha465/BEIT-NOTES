//c program to rotate a trianle by theta degrees
#include <stdio.h>
#include <graphics.h>
#include <math.h>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
void rotateTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int xc, int yc, float theta)
{
    float theta_radian = (3.14159/180)*theta;
    int x1_new = xc + (x1-xc)*cos(theta_radian) - (y1-yc)*sin(theta_radian);
    int y1_new = yc + (x1-xc)*sin(theta_radian) + (y1-yc)*cos(theta_radian);
    int x2_new = xc + (x2-xc)*cos(theta_radian) - (y2-yc)*sin(theta_radian);
    int y2_new = yc + (x2-xc)*sin(theta_radian) + (y2-yc)*cos(theta_radian);
    int x3_new = xc + (x3-xc)*cos(theta_radian) - (y3-yc)*sin(theta_radian);
    int y3_new = yc + (x3-xc)*sin(theta_radian) + (y3-yc)*cos(theta_radian);
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
}
int main()
{
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200, x3 = 300, y3 = 100;
    int xc = 200, yc = 200;
    float theta = 45;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawTriangle(x1, y1, x2, y2, x3, y3);
    rotateTriangle(x1, y1, x2, y2, x3, y3, xc, yc, theta);
    delay(5000);
    closegraph();
    return 0;
}
