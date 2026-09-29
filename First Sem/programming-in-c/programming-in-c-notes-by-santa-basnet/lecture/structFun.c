//Structure and function

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct Point{
    int x, y;
};
struct Point points[100];

//Functions prototypes
void initializePoints();
void getPoint(int, struct Point*);
void printPoint(struct Point);


void getPoint(int i, struct Point *pt){
    if(i >= 0 && i < 100)
        *pt = points[i];
    else{
        pt = NULL;
    }
};

void initializePoints(){
    int i = 0;
    time_t t;
    struct Point tmp;
    srand((unsigned) time(&t));
    for(;i<100;){
        tmp.x = rand() % MAX;
        tmp.y = rand() % MAX;
        points[i++] = tmp;
    }
}

void printPoint(struct Point pt){
    printf("Point is (%d, %d).\n", pt.x, pt.y);
}

int main(){
    struct Point t;
    initializePoints();

    getPoint(30, &t);
    printPoint(t);

    return 0;
}
