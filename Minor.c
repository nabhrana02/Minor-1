#include<stdio.h>
#include<GL/glut.h>

//Interface 1 Design Display.
// Om PAndey push your function here.*(Only the display 		function).
// OM SAYS: DONE BELOW
//Input Function.

void mouse(int button, int state, int x, int y)
{
    //either left click or right click
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
    {
        //storing the coordinates in the array of left click
        Input[0] = x;
        Input[1] = 720 - y;

    }

    case GLUT_RIGHT_BUTTON:
    {
        //storing the coordinates of right click in the array
        Input[0] = x;
        Input[1] = 720 - y;
    }
    glutPostRedisplay();
    }
}


//Processing upon the input.
//Nabh push your code here



//Output based on User's Input.
//Shashank push your code here.
void display_option(int selected1[], int selected2[]){

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(((selected1[2]-selected1[0])/2)-12, selected1[3]+15);
    glVertex2f(((selected1[2]-selected1[0])/2)+12, selected1[3]+15);
    glVertex2f((selected1[2]-selected1[0])/2, selected1[3]+5);
    glEnd();

    glBegin(GL_Polygon);
    glVertex2f(((selected2[2]-selected2[0])/2)-12, selected2[3]+15);
    glVertex2f(((selected2[2]-selected2[0])/2)+12, selected2[3]+15);
    glVertex2f((selected2[2]-selected2[0])/2, selected2[3]+5);
    glEnd();

}




void reshaping(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, 1080, 0, 720);

    glMatrixMode(GL_MODELVIEW);

}



void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}





// driver function for the text drawing which will call the drawStrokeText multiple times with all the values
void drawingText(){

    // the coordinates in the comments will be for the lower left corner of the designated box. The first one is still done
    // to explain things


    // for the main game name window
    // 106 and 587  -> the coordinates for the lower left corner of the box
    char str[] = "Box'em Up";
    glColor3f(1.0,0.0,0.0);
    drawStrokeText(str, 112, 610, 10, 9, 0.67, 0.67);


    // grid


    // for the grid
    // 85 and 407
    char str1[] = "Grid";
    glColor3f(0.9,0,0.4);
    drawStrokeText(str1, 88, 430, 6, 4, 0.4, 0.4);

    // grid options
    char gridOptions[][5] = {"10X10","12X12","15X15","18X18"};

    // for the first grid option
    // 230 and 420
    drawStrokeText(gridOptions[0],232, 436, 4,5, 0.25, 0.25);

    // for the second grid option
    // 350 and 420
    drawStrokeText(gridOptions[1],352, 436, 4,5, 0.25, 0.25);

    // for the third grid option
    // 470 and 420
    drawStrokeText(gridOptions[2],472, 436, 4,5, 0.25, 0.25);

    // for the fourth grid option
    // 590 and 420
    drawStrokeText(gridOptions[3],592, 436, 4,5, 0.25, 0.25);



    //players


    // for players
    // 325 and 347 -> the coordinates for the left andar wala angular part
    char str2[] = "Players";
    glColor3f(0.0,0.2,0.8);
    drawStrokeText(str2, 328, 335, 5, 7, 0.32, 0.32);

    //player name fields
    char playernumber[][5] = {"P1:", "P2:", "P3:", "P4:"};


    // first box
    // 100 and 200
    glColor3f(0.6,0.2,0.4);
    drawStrokeText(playernumber[0], 102, 222, 3, 3, 0.2, 0.2);

    // second box
    // 495 and 200
    drawStrokeText(playernumber[1], 497, 222, 3, 3, 0.2, 0.2);

    // third box
    // 100 and 67
    drawStrokeText(playernumber[2], 102, 89, 3, 3, 0.2, 0.2);

    // fourth box
    // 495 and 67
    drawStrokeText(playernumber[3], 497, 89, 3, 3, 0.2, 0.2);


    // Start
    // 800 and 250 -> left corner of the start button
    char str3[] = "START";
    glColor3f(1.0,1.0,1.0);
    drawStrokeText(str3, 820, 230, 7, 5, 0.4, 0.4);


}



// This is shashank and I am gonna add a text function here for drawing the text in the option boxes
void drawStrokeText(char string[], int x, int y,int linewidth, int length, double scaleA, double scaleB){

    int c;
    glPushMatrix();
    // width of the line drawn on the screen
    glLineWidth(linewidth);
    // position of the text
    glTranslatef(x, y, 0);
    // size of the text
    glScalef(scaleA, scaleB, 0.0);

    // for the actual drawing of the characters
    for(c=0; c<length; c++){
        // we iterate through the string character by character and display it on the screen
        glutStrokeCharacter(GLUT_STROKE_ROMAN, string[c]);

    }
    glPopMatrix();

    glutReshapeFunc(reshaping);

}


void Interface1(){

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
}



// the main display function where all the other functions will be called
void display() {
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);
    // main interface function by OM with all the shapes
    Interface1();

    // text function by SHASHANK to draw the text on the screen
    drawingText();

    // highlighting the option user selected
    display_option(int selected1[], int selected2[]);

    // put everything on the screen
    glutSwapBuffers();
}







int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1080, 720);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Box'em Up");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshaping);

    init();
    glutMainLoop();
}
