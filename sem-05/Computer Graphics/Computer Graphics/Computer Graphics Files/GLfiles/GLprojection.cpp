#include<windows.h>
#include<gl/gl.h>
#include<gl/glu.h>
#include<gl/glut.h>

void display(){
    glClearColor(1,0,0,0); // clears the background color and set it to red
    glClear(GL_COLOR_BUFFER_BIT); //spreads the provided color all over the window
    glColor3f(1,1,0); // color of the objects that will be drawn into the window
    glLoadIdentity();
    gluLookAt(0,0,20, 0,0,0, 0,1,0); //eyeX,eyeY,eyeZ,centerX,centerY,centerZ,upX,upY,upZ
    glPushMatrix();
        glutWireSphere(1,20,20);
    glPopMatrix();
    glFlush(); //sends commands to GPU for execution
}
void reshape(int v, int h){
    glViewport(0,0,v,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0f, (float)v/h, 1.0, 20.0); //field of view angle, aspect ratio, Znear, Zfar
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //GLUT_RGB --> for display color model | GLUT_SINGLE --> for frame buffer (single for graphics, double for animation)
    glutInitWindowSize(500,500); //size of the display window
    glutInitWindowPosition(10,10); // initial position of the display window
    glutCreateWindow("GLProjection!!"); //title of the display window
    glutDisplayFunc(display); //calling the display function --> callback function
    glutReshapeFunc(reshape); //for projection --> callback function
    glutMainLoop(); //Loooping main window to constantly monitor the acticity in the window
    return 0;
}
