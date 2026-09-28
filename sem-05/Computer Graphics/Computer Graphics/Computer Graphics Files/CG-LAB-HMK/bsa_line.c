#include<stdio.h> 
#include<conio.h> 
#include<graphics.h> 
void main() 
	{ 
	int x,y,x1,y1,x2,y2,p,dx,dy; 
	int gdriver=DETECT,gmode; 
	initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI:"); 

	printf("\nEnter the x-coordinate of the first point ::"); 
	scanf("%d",&x1); 
	printf("\nEnter the y-coordinate of the first point ::"); 
	scanf("%d",&y1); 
	printf("\nEnter the x-coordinate of the second point ::"); 
	scanf("%d",&x2); 
	printf("\nEnter the y-coordinate of the second point ::"); 
	scanf("%d",&y2); 
	x=x1; 
	y=y1; 
	dx=x2-x1; 
	dy=y2-y1; 
	float m = dy/dx;
	if (m > 1){

        putpixel(x,y,2);
        p=(2*dx-dy);
        while(x<=x2){
            if(p>0){
                y=y+1;
                x=x+1;
                p=p+2*dx-2*dy;
            }
            else{
                y=y+1;
                x=x;
                p=p+2*dx;
            }
            putpixel(x,y,4);
        }
    }
    else{
        putpixel(x,y,2);
        p=(2*dy-dx);
        while(x<=x2){
            if(p>0){
                x=x+1;
                y=y+1;
                p=p+2*dy-2*dx;
            }
            else{
                x=x+1;
                y=y;
                p=p+2*dy;
            }
            putpixel(x,y,4);
        }
    }
	getch(); 
	closegraph(); 
} 