#include<stdio.h>
#include<GLUT/glut.h>

//Interface 1 Design Display.
// Om PAndey push your function here.*(Only the display 		function).
// OM SAYS: DONE BELOW
//Input Function.
//Himani Push your function here.



//Processing upon the input.
//Nabh push your code here



//Output based on User's Input.
//Shashank push your code here.



void Interface1()
{

    glClear(GL_COLOR_BUFFER_BIT);       // Clear display window

    //COORDINATES ORDER:   Top Left --> Bottom Left --> Bottom Right --> Top Right

    // TOP BOX FOR HEADING/NAME/TITLE
    //OUTER BOX
    glColor3f(0.2, 0.2, 0.5);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(50, 713);
    glVertex2i(100, 580);
    glVertex2i(600, 580);
    glVertex2i(550, 713);
    glEnd();
    //INNER BOX
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(62, 707);
    glVertex2i(106, 587);
    glVertex2i(589, 587);
    glVertex2i(544, 707);
    glEnd();


    // LOGO SPACE
    // OUTER BOX
    glColor3f(0.2, 0.2, 0.5);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(820, 713);
    glVertex2i(870, 580);
    glVertex2i(1070, 580);
    glVertex2i(1020, 713);
    glEnd();
    // INNER BOX SPACE
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(831, 707);
    glVertex2i(875, 587);
    glVertex2i(1059, 587);
    glVertex2i(1014, 707);
    glEnd();


    //GRID OPTIONS
    // MAIN BIG BOX
    glColor3f(0.2, 0.5, 0.2);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(60, 500);
    glVertex2i(60, 400);
    glVertex2i(735, 400);
    glVertex2i(735, 500);
    glEnd();

    // 'GRID: ' BOX
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(85, 493);
    glVertex2i(85, 407);
    glVertex2i(200, 407);
    glVertex2i(200, 493);
    glEnd();

    // GRID OPTIONS' BOXES

    // OPTION NO. #01
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(230, 480);
    glVertex2i(230, 420);
    glVertex2i(330, 420);
    glVertex2i(330, 480);
    glEnd();

    // OPTION NO. #02
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(350, 480);
    glVertex2i(350, 420);
    glVertex2i(450, 420);
    glVertex2i(450, 480);
    glEnd();

    // OPTION NO. #03
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 480);
    glVertex2i(470, 420);
    glVertex2i(570, 420);
    glVertex2i(570, 480);
    glEnd();

    // OPTION NO. #04
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(590, 480);
    glVertex2i(590, 420);
    glVertex2i(690, 420);
    glVertex2i(690, 480);
    glEnd();


    // PLAYER SELECTION:
    // "PLAYERS" TITLE
    glColor3f(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 347);
    glVertex2i(495, 380);
    glVertex2i(300, 380);
    glVertex2i(325, 347);
    glVertex2i(300, 313);
    glVertex2i(495, 313);
    glEnd();


    // Player #03  ( BOTTOM LEFT )
    glColor3f(0.99, 0.99, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 133);
    glVertex2i(100, 67);
    glVertex2i(300, 67);
    glVertex2i(300, 133);
    glEnd();

    // Player #01  ( TOP LEFT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 267);
    glVertex2i(100, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 267);
    glEnd();

    // Player #04  ( BOTTOM RIGHT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 133);
    glVertex2i(495, 67);
    glVertex2i(695, 67);
    glVertex2i(695, 133);
    glEnd();

    // Player #02  ( TOP RIGHT )
    glColor3f(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 267);
    glVertex2i(495, 200);
    glVertex2i(695, 200);
    glVertex2i(695, 267);
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


}



void reshaping(int w, int h) {
	glViewport(0, 0, w, h);
	gluOrtho2D(0, 1080, 0, 720);

}



void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1080, 720);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Box'em Up");

	glutDisplayFunc(display);
	glutReshapeFunc(reshaping);

	init();
	glutMainLoop();
}
