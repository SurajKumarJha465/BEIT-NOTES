#include<stdio.h>

struct Point {
    int x, y;
};
int absValue(int a){
    return a >= 0 ? a : -a;
}
int mDistance(struct Point p1, struct Point p2){
    return absValue(p1.x-p2.x) + absValue(p1.y-p2.y);
}

int main(){
    struct Point p1 = {2, 3}, p2 = {4, 6}, p3 = {20, 21};

    int d1 = mDistance(p1, p2);
    int d2 = mDistance(p2, p3);
    if(d1 > d2) printf("P3 is closer P2");
    else if(d1 == d2) printf("Both points are in Equal distance.");
    else printf("P1 is closer to P2");

    return 0;
}