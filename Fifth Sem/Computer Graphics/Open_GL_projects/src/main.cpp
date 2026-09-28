#include <GL/glut.h>   // GLUT, OpenGL Utility Toolkit
#include <GLFW/glfw3.h> // GLFW, window and input management

/* --------------------------------------------------
   Function to draw everything on the screen
-------------------------------------------------- */
void display()
{
    // Clear the screen with background color
    glClear(GL_COLOR_BUFFER_BIT);

    // /* ----------- Drawing a LINE ----------- */
    // glPointSize(30.0f);            // Increased point size
    // glColor3f(1.0f, 0.0f, 0.0f);   // Red color

    // glBegin(GL_LINES);            // FIXED (plural)
    //     glVertex2f(-0.8f, 0.8f);
    //     glVertex2f( 0.8f, 0.8f);
    // glEnd();

    // /* ----------- Drawing a TRIANGLE ----------- */
    // // glColor3f(0.0f, 1.0f, 0.0f);  // Green color
    // glBegin(GL_LINE_LOOP);
    //     glVertex2f(-0.5f, -0.2f); // Vertex 1
    //     glVertex2f(0.0f, 0.6f);   // Vertex 2
    //     glVertex2f(0.5f, -0.2f);  // Vertex 3
    // glEnd();

    /* ----------- Drawing a POLYGON ----------- */
    glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
    glBegin(GL_POLYGON);
        glVertex2f(-0.6f, -0.8f);
        glVertex2f(-0.2f, -0.4f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.6f, -0.8f);
    glEnd();

    // Render everything on screen
    glFlush();
}

/* --------------------------------------------------
   Main Function
-------------------------------------------------- */
int main(int argc, char** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set display mode (Single buffer + RGB color)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Set window size
    glutInitWindowSize(800, 600);

    // Set window position
    glutInitWindowPosition(100, 100);

    // Create window with title
    glutCreateWindow("Basic OpenGL: Line, Triangle, Polygon");

    // Set background color (Black)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Tell GLUT which function to call for drawing
    glutDisplayFunc(display);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
