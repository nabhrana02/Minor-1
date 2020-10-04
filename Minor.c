#include<stdio.h>
#include<GL/glut.h>
#include<stdbool.h>

//Defining global variables.
double Input[2] = { -50, -50 };
double Cord[9][4];
double Selected1[4];
double Selected2[4];
int Set_Interface = 1;
int xi;
int  yi;
bool First = false, Second = false;


//Defining all funcitons.
void mouse(int button, int state, int x, int y);
void Process();
void reshaping(int w, int h);
void init();
void drawingText();
void drawStrokeText(char string[], int x, int y, int linewidth, int length, double scaleA, double scaleB);
void Interface1();
void Interface2();
void display();
void display_option();


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1080, 720);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Box'em Up");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshaping);

    init();
    glutMainLoop();
}



//Function to take input from the user.
void mouse(int button, int state, int x, int y)
{
    //either left click or right click
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
    {
        //storing the coordinates in the array of left click
        Input[0] = x;
        xi = Input[0];
        Input[1] = 720 - y;
        yi = Input[1];
    }

    case GLUT_RIGHT_BUTTON:
    {
        //storing the coordinates of right click in the array
        Input[0] = x;
        xi = Input[0];
        Input[1] = 720 - y;
        yi = Input[1];
    }

    }

    glutPostRedisplay();

}



// the main display function where all the other functions will be called
void display() {
    // clear the buffer

        // main interface function by OM with all the shapes
    if (Set_Interface == 1)
    {
        Interface1();
        // text function by SHASHANK to draw the text on the screen
        drawingText();

        Process();

        display_option();
        glColor3f(0.0, 1.0, 0.0);
        glPointSize(20.0);
        glBegin(GL_POINTS);
        glVertex2d(xi, yi);
        glEnd();
        // put everything on the screen
        glFlush();
    }

    if (Set_Interface == 2)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();

    }
    glFlush();
}




void reshaping(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, 1080, 0, 720);

    glMatrixMode(GL_MODELVIEW);

}

void init() {
    glClearColor(0.8, 0.8, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}




//Function where Input will be processed
void Process() {



    for (int i = 0; i < 4; i++) {
        if (First == false && xi > Cord[i][0] && xi < Cord[i][2] && yi>Cord[i][1] && yi < Cord[i][3]) {
            for (int j = 0; j < 4; j++) {
                Selected1[j] = Cord[i][j];
            }
            First = true;
        }
    }
    for (int i = 4; i < 8; i++) {
        if (Second == false && xi > Cord[i][0] && xi < Cord[i][2] && yi>Cord[i][1] && yi < Cord[i][3]) {
            for (int j = 0; j < 4; j++) {
                Selected2[j] = Cord[i][j];
            }
            Second = true;
        }
    }

    if (First == true && Second == true && xi > Cord[8][0] && xi < Cord[8][2] && yi > Cord[8][1] && yi < Cord[8][3]) {
        Set_Interface = 2;

    }
}







// driver function for the text drawing which will call the drawStrokeText multiple times with all the values
void drawingText() {

    // the coordinates in the comments will be for the lower left corner of the designated box. The first one is still done
    // to explain things


    // for the main game name window
    // 106 and 587  -> the coordinates for the lower left corner of the box
    char str[] = "Box'em Up";
    glColor3f(1.0, 0.0, 0.0);
    drawStrokeText(str, 112, 610, 10, 9, 0.67, 0.67);


    // grid


    // for the grid
    // 85 and 407
    char str1[] = "Grid";
    glColor3d(0.9, 0.0, 0.4);
    drawStrokeText(str1, 88, 430, 6, 4, 0.4, 0.4);

    // grid options
    char gridOptions[][6] = { "10X10","12X12","15X15","18X18" };

    // for the first grid option
    // 230 and 420
    drawStrokeText(gridOptions[0], 232, 436, 4, 5, 0.25, 0.25);

    // for the second grid option
    // 350 and 420
    drawStrokeText(gridOptions[1], 352, 436, 4, 5, 0.25, 0.25);

    // for the third grid option
    // 470 and 420
    drawStrokeText(gridOptions[2], 472, 436, 4, 5, 0.25, 0.25);

    // for the fourth grid option
    // 590 and 420
    drawStrokeText(gridOptions[3], 592, 436, 4, 5, 0.25, 0.25);



    //players


    // for players
    // 325 and 347 -> the coordinates for the left andar wala angular part
    char str2[] = "Players";
    glColor3d(0.0, 0.2, 0.8);
    drawStrokeText(str2, 328, 335, 5, 7, 0.32, 0.32);

    //player name fields
    char playernumber[][5] = { "P1:", "P2:", "P3:", "P4:" };


    // first box
    // 100 and 200
    glColor3d(0.6, 0.2, 0.4);
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
    glColor3d(1.0, 1.0, 1.0);
    drawStrokeText(str3, 820, 230, 7, 5, 0.4, 0.4);


}



// This is shashank and I am gonna add a text function here for drawing the text in the option boxes
void drawStrokeText(char string[], int x, int y, int linewidth, int length, double scaleA, double scaleB) {

    int c;
    glPushMatrix();
    // width of the line drawn on the screen
    glLineWidth(linewidth);
    // position of the text
    glTranslatef(x, y, 0);
    // size of the text
    glScalef(scaleA, scaleB, 0.0);

    // for the actual drawing of the characters
    for (c = 0; c < length; c++) {
        // we iterate through the string character by character and display it on the screen
        glutStrokeCharacter(GLUT_STROKE_ROMAN, string[c]);

    }
    glPopMatrix();

    glutReshapeFunc(reshaping);

}

void display_option() {

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f((((Selected1[2] - Selected1[0]) / 2) - 14) + Selected1[0], Selected1[3] + 17);
    glVertex2f((((Selected1[2] - Selected1[0]) / 2) + 14) + Selected1[0], Selected1[3] + 17);
    glVertex2f(((Selected1[2] - Selected1[0]) / 2) + Selected1[0], Selected1[3] + 5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((((Selected2[2] - Selected2[0]) / 2) - 14) + Selected2[0], Selected2[3] + 17);
    glVertex2f((((Selected2[2] - Selected2[0]) / 2) + 14) + Selected2[0], Selected2[3] + 17);
    glVertex2f(((Selected2[2] - Selected2[0]) / 2) + Selected2[0], Selected2[3] + 5);
    glEnd();

}

void Interface1() {

    //COORDINATES ORDER:   Top Left --> Bottom Left --> Bottom Right --> Top Right

    // TOP BOX FOR HEADING/NAME/TITLE
    //OUTER BOX
    glColor3d(0.2, 0.2, 0.5);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(50, 713);
    glVertex2i(100, 580);
    glVertex2i(600, 580);
    glVertex2i(550, 713);
    glEnd();
    //INNER BOX
    glColor3d(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(62, 707);
    glVertex2i(106, 587);
    glVertex2i(589, 587);
    glVertex2i(544, 707);
    glEnd();


    // LOGO SPACE
    // OUTER BOX
    glColor3d(0.2, 0.2, 0.5);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(820, 713);
    glVertex2i(870, 580);
    glVertex2i(1070, 580);
    glVertex2i(1020, 713);
    glEnd();
    // INNER BOX SPACE
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(831, 707);
    glVertex2i(875, 587);
    glVertex2i(1059, 587);
    glVertex2i(1014, 707);
    glEnd();


    //GRID OPTIONS
    // MAIN BIG BOX
    glColor3d(0.2, 0.5, 0.2);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(60, 500);
    glVertex2i(60, 400);
    glVertex2i(735, 400);
    glVertex2i(735, 500);
    glEnd();

    // 'GRID: ' BOX
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(85, 493);
    glVertex2i(85, 407);
    glVertex2i(200, 407);
    glVertex2i(200, 493);
    glEnd();

    // GRID OPTIONS' BOXES

    // OPTION NO. #01
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(230, 480);
    glVertex2i(230, 420);
    glVertex2i(330, 420);
    glVertex2i(330, 480);
    glEnd();

    Cord[0][0] = 230;
    Cord[0][1] = 420;
    Cord[0][2] = 330;
    Cord[0][3] = 480;

    // OPTION NO. #02
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(350, 480);
    glVertex2i(350, 420);
    glVertex2i(450, 420);
    glVertex2i(450, 480);
    glEnd();

    Cord[1][0] = 350;
    Cord[1][1] = 420;
    Cord[1][2] = 450;
    Cord[1][3] = 480;

    // OPTION NO. #03
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 480);
    glVertex2i(470, 420);
    glVertex2i(570, 420);
    glVertex2i(570, 480);
    glEnd();

    Cord[2][0] = 470;
    Cord[2][1] = 420;
    Cord[2][2] = 570;
    Cord[2][3] = 480;

    // OPTION NO. #04
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(590, 480);
    glVertex2i(590, 420);
    glVertex2i(690, 420);
    glVertex2i(690, 480);
    glEnd();

    Cord[3][0] = 590;
    Cord[3][1] = 420;
    Cord[3][2] = 690;
    Cord[3][3] = 480;


    // PLAYER SELECTION:
    // "PLAYERS" TITLE
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(470, 347);
    glVertex2i(495, 380);
    glVertex2i(300, 380);
    glVertex2i(325, 347);
    glVertex2i(300, 313);
    glVertex2i(495, 313);
    glEnd();


    // Player #03  ( BOTTOM LEFT )
    glColor3d(0.99, 0.99, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 133);
    glVertex2i(100, 67);
    glVertex2i(300, 67);
    glVertex2i(300, 133);
    glEnd();

    Cord[6][0] = 100;
    Cord[6][1] = 67;
    Cord[6][2] = 300;
    Cord[6][3] = 133;

    // Player #01  ( TOP LEFT )
    glColor3d(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(100, 267);
    glVertex2i(100, 200);
    glVertex2i(300, 200);
    glVertex2i(300, 267);
    glEnd();

    Cord[4][0] = 100;
    Cord[4][1] = 200;
    Cord[4][2] = 300;
    Cord[4][3] = 267;

    // Player #04  ( BOTTOM RIGHT )
    glColor3d(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 133);
    glVertex2i(495, 67);
    glVertex2i(695, 67);
    glVertex2i(695, 133);
    glEnd();


    Cord[7][0] = 495;
    Cord[7][1] = 67;
    Cord[7][2] = 695;
    Cord[7][3] = 133;

    // Player #02  ( TOP RIGHT )
    glColor3d(0.99, 0.99, 0.99);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(495, 267);
    glVertex2i(495, 200);
    glVertex2i(695, 200);
    glVertex2i(695, 267);
    glEnd();

    Cord[5][0] = 495;
    Cord[5][1] = 200;
    Cord[5][2] = 695;
    Cord[5][3] = 267;


    // START BUTTON
    glBegin(GL_POLYGON);

    glColor3d(0.0, 0.0, 1.0);
    glVertex2i(900, 350);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(800, 250);

    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(900, 150);

    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(1000, 250);
    glEnd();

    Cord[8][0] = 800;
    Cord[8][1] = 150;
    Cord[8][2] = 1000;
    Cord[8][3] = 350;
}


void Interface2() 
{
    if (size == 4) {
        yg = 60;
        xg = 80;
        xmax = 840;
        ymax = 600;
        total = 1;
    }
    if (size == 3) {
        yg = 65;
        xg = 85;
        ymax = 585;
        xmax = 765;
        total = 64;
    }
    if (size == 2) {
        yg = 70;
        xg = 95;
        xmax = 800;
        ymax = 600;
        total = 49;
    }
    if (size == 1) {
        yg = 80;
        ymax = 500;
        xg = 110;
        xmax = 660;
        total = 25;
    }

    int k = 0;
    for (int i = xg; i <= xmax; i = i + xg) {

        for (int j = yg; j <= ymax; j = j + yg) {

            glPointSize(12.0);
            glColor3d(1.0, 1.0, 1.0);
            glBegin(GL_POINTS);
            glVertex2f(i, j);
            glEnd();
            if (j + yg <= ymax) {
                LineCord[k][0] = i;
                LineCord[k][1] = j;
                LineCord[k][2] = i;
                LineCord[k][3] = j + yg;


                glColor3d(0.1, 0.1, 0.1);
                glLineWidth(10.0);
                glBegin(GL_LINES);
                glVertex2f(LineCord[k][0], LineCord[k][1] + 10);
                glVertex2f(LineCord[k][2], LineCord[k][3] - 10);
                glEnd();
                k = k + 1;
            }
            if (i + xg <= xmax) {
                LineCord[k][0] = i;
                LineCord[k][1] = j;
                LineCord[k][2] = i + xg;
                LineCord[k][3] = j;


                glColor3d(0.1, 0.1, 0.1);
                glLineWidth(10.0);
                glBegin(GL_LINES);
                glVertex2f(LineCord[k][0] + 10, LineCord[k][1]);
                glVertex2f(LineCord[k][2] - 10, LineCord[k][3]);
                glEnd();
                k = k + 1;
            }

        }
    }
}

void Process2() {
    int a = yi % yg;
    int b = xi % xg;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    bool notyet = false;
    bool fill = false;
    top1 = false;
    top2 = false;
    bottom1 = false;
    bottom2 = false;
    ver1 = false;
    ver2 = false;
    left1 = false;
    left2 = false;
    right1 = false;
    right2 = false;
    hor1 = false;
    hor2 = false;
    point = 0;

    if (a < 15 && yi < ymax && xi < xmax) {
        if (a < b && a < xg - b) {
            x1 = xi - b;
            y1 = yi - a;
            x2 = x1 + xg;
            y2 = y1;
            fill = true;
            notyet = true;
        }

    }
    else if (a > 45 && yi < ymax && xi < xmax) {
        if (yg - a < b && yg - a < xg - b) {
            x1 = xi - b;
            y1 = yi - a + yg;
            x2 = x1 + xg;
            y2 = y1;
            fill = true;
            notyet = true;
        }

    }
    if (b < 20 && notyet == false && yi < ymax && xi < xmax) {
        if (b < a && b < yg - a) {
            x1 = xi - b;
            y1 = yi - a;
            x2 = x1;
            y2 = y1 + yg;
            fill = true;
        }

    }
    else if (b > yg && notyet == false && yi < ymax && xi < xmax) {
        if (xg - b < a && 80 - b < yg - a) {
            x1 = xi - b + xg;
            y1 = yi - a;
            x2 = x1;
            y2 = y1 + yg;
            fill = true;
        }

    }
    for (int s = 0; s < 200; s++) {
        if (SelOption[s][0] == x1 && SelOption[s][1] == y1 && SelOption[s][2] == x2 && SelOption[s][3] == y2) {
            fill = false;
            break;
        }
    }
    if (fill == true) {
        SelOption[n][0] = x1;
        SelOption[n][1] = y1;
        SelOption[n][2] = x2;
        SelOption[n][3] = y2;
        n = n + 1;


        if (x1 == x2) {
            for (int p = 0; p < 200; p++) {
                if (SelOption[p][0] == (x1 - xg) && SelOption[p][1] == y1 && SelOption[p][2] == (x2 - xg) && SelOption[p][3] == y2)
                    ver1 = true;
                if (SelOption[p][0] == (x1 + xg) && SelOption[p][1] == y1 && SelOption[p][2] == (x1 + xg) && SelOption[p][3] == y2)
                    ver2 = true;
                if (SelOption[p][0] == (x2 - xg) && SelOption[p][1] == y2 && SelOption[p][2] == x2 && SelOption[p][3] == y2)
                    top1 = true;
                if (SelOption[p][0] == x2 && SelOption[p][1] == y2 && SelOption[p][2] == (x2 + xg) && SelOption[p][3] == y2)
                    top2 = true;
                if (SelOption[p][0] == (x1 - xg) && SelOption[p][1] == y1 && SelOption[p][2] == x1 && SelOption[p][3] == y1)
                    bottom1 = true;
                if (SelOption[p][0] == x1 && SelOption[p][1] == y1 && SelOption[p][2] == (x1 + xg) && SelOption[p][3] == y1)
                    bottom2 = true;
            }
        }
        if (y1 == y2) {
            for (int p = 0; p < 200; p++) {
                if (SelOption[p][0] == x1 && SelOption[p][1] == (y1 - yg) && SelOption[p][2] == x2 && SelOption[p][3] == (y2 - yg))
                    hor1 = true;
                if (SelOption[p][0] == x1 && SelOption[p][1] == (y1 + yg) && SelOption[p][2] == x2 && SelOption[p][3] == (y2 + yg))
                    hor2 = true;
                if (SelOption[p][0] == x1 && SelOption[p][1] == (y1 - yg) && SelOption[p][2] == x1 && SelOption[p][3] == y1)
                    left1 = true;
                if (SelOption[p][0] == x1 && SelOption[p][1] == y1 && SelOption[p][2] == x1 && SelOption[p][3] == (y1 + yg))
                    left2 = true;
                if (SelOption[p][0] == x2 && SelOption[p][1] == (y2 - yg) && SelOption[p][2] == x2 && SelOption[p][3] == y2)
                    right1 = true;
                if (SelOption[p][0] == x2 && SelOption[p][1] == y2 && SelOption[p][2] == x2 && SelOption[p][3] == (y2 + yg))
                    right2 = true;

            }
        }

        if (top1 && bottom1 && ver1) {
            Points[q][0] = x1 - xg;
            Points[q][1] = y1;
            Points[q][2] = x1;
            Points[q][3] = y2;
            q = q + 1;
            point = point + 1;
        }
        if (top2 && bottom2 && ver2) {
            Points[q][0] = x1;
            Points[q][1] = y1;
            Points[q][2] = x1 + xg;
            Points[q][3] = y2;
            q = q + 1;
            point = point + 1;
        }
        if (right1 && left1 && hor1) {
            Points[q][0] = x1;
            Points[q][1] = y1 - yg;
            Points[q][2] = x2;
            Points[q][3] = y2;
            q = q + 1;
            point = point + 1;
        }
        if (right2 && left2 && hor2) {
            Points[q][0] = x1;
            Points[q][1] = y1;
            Points[q][2] = x2;
            Points[q][3] = y2 + yg;
            q = q + 1;
            point = point + 1;
        }
    }

    if (fill) {
        if (point > 0) {
            count[player] = count[player] + point;
            if (point == 1) {
                Playcolor[q - 1] = player;
            }
            if (point == 2) {
                Playcolor[q - 1] = player;
                Playcolor[q - 2] = player;
            }
        }
        else {
            if (player == 0 || player == 1 || player == 2 || player == 3) {
                player = player + 1;
            }
            if (player > players - 1) {
                player = 0;
            }
        }
    }



    if (q == total) {
        Set_Interface = 3;
    }

    for (int m = 0; m < 200; m++) {
        glColor3d(0.9, 0.9, 0.9);
        glLineWidth(10.0);
        glBegin(GL_LINES);
        glVertex2f(SelOption[m][0], SelOption[m][1]); 
        glVertex2f(SelOption[m][2], SelOption[m][3]);
        glEnd();
    }
    for (int m = 0; m < 90; m++) {
        glColor3f(colors[Playcolor[m]][0], colors[Playcolor[m]][1], colors[Playcolor[m]][2]);
        glBegin(GL_POLYGON);
        glVertex2f(Points[m][0] + 7, Points[m][1] + 7);
        glVertex2f(Points[m][2] - 7, Points[m][1] + 7);
        glVertex2f(Points[m][2] - 7, Points[m][3] - 7);
        glVertex2f(Points[m][0] + 7, Points[m][3] - 7);
        glEnd();
    }
}