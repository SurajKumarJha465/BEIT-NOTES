#include <graphics.h> 
#include <dos.h>
#include <conio.h>	
void boundaryFill(int x, int y, int fill_color,int boundary_color) 
{ 
	if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) 
	{ 
		putpixel(x, y, fill_color); 
        delay(20);
		boundaryFill(x + 1, y, fill_color, boundary_color); 
		boundaryFill(x, y + 1, fill_color, boundary_color); 
		boundaryFill(x - 1, y, fill_color, boundary_color); 
		boundaryFill(x, y - 1, fill_color, boundary_color); 
        //boundaryFill(x + 1, y + 1, fill_color, boundary_color);
        //boundaryFill(x - 1, y + 1, fill_color, boundary_color);   
        //boundaryFill(x + 1, y - 1, fill_color, boundary_color);
        //boundaryFill(x - 1, y - 1, fill_color, boundary_color);
	} 
} 	
int main() 
{  
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, ""); 	
	int x = 250, y = 200, radius = 50; 
	circle(x, y, radius); 
	boundaryFill(x, y, 6, 15); 	
	getch();  
	closegraph(); 	
	return 0; 
}