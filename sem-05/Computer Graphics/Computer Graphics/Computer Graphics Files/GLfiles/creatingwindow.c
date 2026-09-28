#include<windows.h>
#include<gl/gl.h>
#include<gl/glu.h>
#include<gl/glut.h>

void display(){
    glClearColor(1,0,0,0); // clears the background color and set it to red
    glClear(GL_COLOR_BUFFER_BIT); //spreads the provided color all over the window
           
    glFlush(); //sends commands to GPU for execution
}


void main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //GLUT_RGB --> for display color model | GLUT_SINGLE --> for frame buffer (single for graphics, double for animation)
    glutInitWindowSize(500,500); //size of the display window 
    glutInitWindowPosition(10,10); // initial position of the display window
    glutCreateWindow("LearningOpenGL!!"); //title of the display window
    glutDisplayFunc(display); //calling the display function --> callback function
    glutMainLoop(); //Loooping main window to constantly monitor the acticity in the window
}