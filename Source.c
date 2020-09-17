#include <windows.h>  // For Microsoft Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.0, 0.0, 0.0, 0.1);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 1080, 0.0, 1080);
}

void Interface1()
{

    glClear(GL_COLOR_BUFFER_BIT);       // Clear display window

    //COORDINATES ORDER:   Top Left --> Bottom Left --> Bottom Right --> Top Right

    // TOP BOX FOR HEADING/NAME/TITLE
    //OUTER BOX
    glColor3f(1.0, 1.0, 0.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(50, 1070);
    glVertex2i(100, 870);
    glVertex2i(600, 870);
    glVertex2i(550, 1070);
    glEnd();
    //INNER BOX
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(62, 1060);
    glVertex2i(106, 880);
    glVertex2i(589, 880);
    glVertex2i(544, 1060);
    glEnd();


    // LOGO SPACE
    // OUTER BOX
    glColor3f(1.0, 1.0, 0.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(820, 1070);
    glVertex2i(870, 870);
    glVertex2i(1070, 870);
    glVertex2i(1020, 1070);
    glEnd();
    // INNER BOX SPACE
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(831, 1060);
    glVertex2i(875, 880);
    glVertex2i(1059, 880);
    glVertex2i(1014, 1060);
    glEnd();


    //GRID OPTIONS
    // MAIN BIG BOX
    glColor3f(0.99, 0.99, 0.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(60, 750);
    glVertex2i(60, 600);
    glVertex2i(710, 600);
    glVertex2i(710, 750);
    glEnd();

    // 'GRID: ' BOX
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(85, 740);
    glVertex2i(85, 610);
    glVertex2i(200, 610);
    glVertex2i(200, 740);
    glEnd();

    // GRID OPTIONS' BOXES

    // OPTION NO. #01
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(230, 720);
    glVertex2i(230, 630);
    glVertex2i(330, 630);
    glVertex2i(330, 720);
    glEnd();

    // OPTION NO. #02
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(350, 720);
    glVertex2i(350, 630);
    glVertex2i(450, 630);
    glVertex2i(450, 720);
    glEnd();

    // OPTION NO. #03
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 720);
    glVertex2i(470, 630);
    glVertex2i(570, 630);
    glVertex2i(570, 720);
    glEnd();

    // OPTION NO. #04
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(590, 720);
    glVertex2i(590, 630);
    glVertex2i(690, 630);
    glVertex2i(690, 720);
    glEnd();


    // PLAYER SELECTION:
    // "PLAYERS" TITLE
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 475+25+20);
    glVertex2i(495, 500+25+25+20);
    glVertex2i(300, 500+25+25+20);
    glVertex2i(325, 475+25+20);
    glVertex2i(300, 450+20);
    glVertex2i(495, 450+20);
    glEnd();


    // Player #03  ( BOTTOM LEFT )
    glColor3f(0.99, 0.99, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 200);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(300, 200);
    glEnd();
    
    // Player #01  ( TOP LEFT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 400);
    glVertex2i(100, 300);
    glVertex2i(300, 300);
    glVertex2i(300, 400);
    glEnd();

    // Player #04  ( BOTTOM RIGHT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 200);
    glVertex2i(495, 100);
    glVertex2i(695, 100);
    glVertex2i(695, 200);
    glEnd();

    // Player #02  ( TOP RIGHT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 400);
    glVertex2i(495, 300);
    glVertex2i(695, 300);
    glVertex2i(695, 400);
    glEnd();

    
    // START BUTTON
    glBegin(GL_POLYGON);

    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(900, 350);
    
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(800, 250);
    
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(900, 150);
    
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(1000, 250);
    glEnd();


    //END
    glFlush();
}

void display() {
    Interface1();
    glFlush();

}

void reshaping() {
    //glViewport();
    //gluOrtho2D(0, 1080, 0, 1080);

}

/* Main function: GLUT runs as a console application starting at main()  */
void main(int argc, char** argv) {
    glutInit(&argc, argv);        
    // Initialize GLUT
    //glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Box 'em Up"); // Create a window with the given title
    glutInitWindowSize(1080, 720);   // Set the window's initial width & height
    glutInitWindowPosition(750, 750); // Position of the window
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint

    //glutReshapeFunc(reshaping);

    glutMainLoop();           // Enter the infinitely event-processing loop
}