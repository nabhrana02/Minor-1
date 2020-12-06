#include<stdio.h>
#include<GLUT/glut.h>
#include<stdbool.h>

//Defining global variables.
double Input[2] = { -50, -50 };
double Cord[9][4];
double Selected1[4];
double Selected2[4];
int Set_Interface = 1;
int Call_I2 = 0;
int xi;
int  yi;
int players;
bool First = false, Second = false;
double LineCord[200][4];
double SelOption[200][4];
double Points[90][4];
int n = 0, q = 0;
bool top1, top2, bottom1, bottom2, ver1, ver2, left1, left2, right1, right2, hor1, hor2;
int count[4];
int player = 0;
int point;
double colors[4][3] = { {1.0, 0.0, 0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{0.8,0.5,0.8} };
int Playcolor[90];
int size, xg, yg, xmax, ymax;
int total;
int max;
int f = sizeof count / sizeof count[0];
int cnd = 0;
int winy = 0;


//Defining all funcitons
void Process2();
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
void Interface3();
void Interface3Text();
void tostring(char str[], int num);
void Winner();


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
        glClear(GL_COLOR_BUFFER_BIT);
        Interface1();
        // text function by SHASHANK to draw the text on the screen
        drawingText();

        Process();

        display_option();

        // put everything on the screen
        glutSwapBuffers();
    }

    else if (Set_Interface == 2)
    {
        if (Call_I2 < 2)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            Interface2();
            Call_I2 = Call_I2 + 1;
        }
        Process2();
        glutSwapBuffers();

    }
    else if (Set_Interface == 3) {
        Interface3();
        glutSwapBuffers();
    }
}



void reshaping(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, 1080, 0, 720);

    glMatrixMode(GL_MODELVIEW);

}

void init() {
    glClearColor(0.6, 0.8, 0.9, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
//0.6, 0.8, 0.9



//Function where Input will be processed
void Process()
{



    for (int i = 0; i < 4; i++) {
        if (First == false && xi > Cord[i][0] && xi < Cord[i][2] && yi>Cord[i][1] && yi < Cord[i][3]) {
            for (int j = 0; j < 4; j++) {
                Selected1[j] = Cord[i][j];
            }
            First = true;
            size = i + 1;
            cnd = 23;
        }
    }
    for (int i = 4; i < 8; i++) {
        if (Second == false && xi > Cord[i][0] && xi < Cord[i][2] && yi>Cord[i][1] && yi < Cord[i][3]) {
            for (int j = 0; j < 4; j++) {
                Selected2[j] = Cord[i][j];
            }
            Second = true;
            players = i - 3;

            cnd = 420;

        }
    }

    // Start button -> 1st animation
    if (cnd == 23)
    {

        // START BUTTON
        glBegin(GL_POLYGON);

        glColor3d(0.1, 0.2, 0.6);
        glVertex2i(900, 300);

        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(800, 200);

        glColor3f(0.1, 0.2, 0.6);
        glVertex2i(900, 100);

        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(1000, 200);
        glEnd();


    }
    // Start button -> 2nd animation
    if (cnd == 420)
    {
        // START BUTTON
        glBegin(GL_POLYGON);

        glColor3d(0.1, 0.2, 0.6);
        glVertex2i(900, 300);

        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(800, 200);

        glColor3f(0.1, 0.2, 0.6);
        glVertex2i(900, 100);

        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(1000, 200);
        glEnd();

        char str3[] = "START";
        //glColor3d(0.6, 0.8, 0.9);
        glColor3d(0.6, 0.8, 0.9);
        drawStrokeText(str3, 820, 180, 7, 5, 0.4, 0.4);
    }

    if (First == true && Second == true && xi > Cord[8][0] && xi < Cord[8][2] && yi > Cord[8][1] && yi < Cord[8][3])
    {
        // START BUTTON
        glBegin(GL_POLYGON);

        glColor3d(0.0, 0.0, 0.0);
        glVertex2i(900, 300);

        glColor3f(0.1, 0.2, 0.6);
        glVertex2i(800, 200);

        glColor3f(0.0, 0.0, 0.0);
        glVertex2i(900, 100);

        glColor3f(0.1, 0.2, 0.6);
        glVertex2i(1000, 200);
        glEnd();

        char str3[] = "START";
        //glColor3d(0.6, 0.8, 0.9);
        glColor3d(0.99, 0.08, 0.09);
        drawStrokeText(str3, 820, 180, 7, 5, 0.4, 0.4);

        Set_Interface = 2;

    }


}







// driver function for the text drawing which will call the drawStrokeText multiple times with all the values
void drawingText() {

    // the coordinates in the comments will be for the lower left corner of the designated box. The first one is still done
    // to explain things


    // for the main game name window
    // 106 and 587  -> the coordinates for the lower left corner of the box
    char str[] = "Box 'em Up";
    glColor3f(0.5, 0.0, 0.0);
    drawStrokeText(str, 270, 550, 10, 10, 0.67, 0.67);


    // grid


    // for the grid
    // 85 and 407
    char str1[] = "Grid: ";
    glColor3d(0.2, 0.0, 0.4);
    drawStrokeText(str1, 88, 430, 6, 6, 0.5, 0.5);

    // grid options
    char gridOptions[][8] = { "Small","Medium ","Large","X-Large" };
    glColor3d(0.6, 0.0, 0.0);
    // for the first grid option
    // 230 and 420
    drawStrokeText(gridOptions[0], 255, 436, 4, 5, 0.25, 0.25);

    // for the second grid option
    // 350 and 420
    drawStrokeText(gridOptions[1], 400, 436, 4, 7, 0.25, 0.25);

    // for the third grid option
    // 470 and 420
    drawStrokeText(gridOptions[2], 590, 436, 4, 7, 0.25, 0.25);

    // for the fourth grid option
    // 590 and 420
    drawStrokeText(gridOptions[3], 730, 436, 4, 7, 0.25, 0.25);



    //players


    // for players
    // 325 and 347 -> the coordinates for the left andar wala angular part
    char str2[] = "No. of Players";
    glColor3d(0.2, 0.0, 0.4);
    drawStrokeText(str2, 250, 320, 5, 14, 0.32, 0.32);

    //player name fields
    char playernumber[][10] = { "1 Player", "2 Players", "3 Players", "4 Players" };


    // first box
    // 100 and 200
    glColor3d(0.5, 0.0, 0.0);
    drawStrokeText(playernumber[0], 127, 222, 4, 9, 0.2, 0.2);

    // second box
    // 495 and 200
    drawStrokeText(playernumber[1], 522, 222, 4, 9, 0.2, 0.2);

    // third box
    // 100 and 67
    drawStrokeText(playernumber[2], 127, 89, 4, 9, 0.2, 0.2);

    // fourth box
    // 495 and 67
    drawStrokeText(playernumber[3], 522, 89, 4, 9, 0.2, 0.2);


    // Start
    // 800 and 250 -> left corner of the start button
    char str3[] = "START";
    //glColor3d(0.6, 0.8, 0.9);
    glColor3d(0.1, 0.2, 0.6);
    drawStrokeText(str3, 820, 180, 7, 5, 0.4, 0.4);


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
    glBegin(GL_LINE_LOOP);
    glVertex2f(Selected1[0], Selected1[3]);
    glVertex2f(Selected1[2], Selected1[3]);
    glVertex2f(Selected1[2], Selected1[1]);
    glVertex2f(Selected1[0], Selected1[1]);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(Selected2[0], Selected2[3]);
    glVertex2f(Selected2[2], Selected2[3]);
    glVertex2f(Selected2[2], Selected2[1]);
    glVertex2f(Selected2[0], Selected2[1]);
    glEnd();

}

void Interface1() {

    //COORDINATES ORDER:   Top Left --> Bottom Left --> Bottom Right --> Top Right

    // GRID OPTIONS' BOXES
    glLineWidth(3);
    // OPTION NO. #01
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(230, 480);
    glVertex2i(230, 420);
    glVertex2i(360, 420);
    glVertex2i(360, 480);
    glEnd();

    Cord[0][0] = 230;
    Cord[0][1] = 420;
    Cord[0][2] = 360;
    Cord[0][3] = 480;

    // OPTION NO. #02
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(380, 480);
    glVertex2i(380, 420);
    glVertex2i(540, 420);
    glVertex2i(540, 480);
    glEnd();

    Cord[1][0] = 380;
    Cord[1][1] = 420;
    Cord[1][2] = 540;
    Cord[1][3] = 480;

    // OPTION NO. #03
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(560, 480);
    glVertex2i(560, 420);
    glVertex2i(690, 420);
    glVertex2i(690, 480);
    glEnd();

    Cord[2][0] = 560;
    Cord[2][1] = 420;
    Cord[2][2] = 690;
    Cord[2][3] = 480;

    // OPTION NO. #04
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(710, 480);
    glVertex2i(710, 420);
    glVertex2i(870, 420);
    glVertex2i(870, 480);
    glEnd();

    Cord[3][0] = 710;
    Cord[3][1] = 420;
    Cord[3][2] = 870;
    Cord[3][3] = 480;


    // PLAYER SELECTION:
    // "No. of Players" TITLE
    glColor3d(0.5, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(470 + 100, 335);
    glVertex2i(495 + 100, 370);
    glVertex2i(300 - 100, 370);
    glVertex2i(325 - 100, 335);
    glVertex2i(300 - 100, 300);
    glVertex2i(495 + 100, 300);
    glEnd();


    // Player #03  ( BOTTOM LEFT )
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
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
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
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
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
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
    glColor3d(0.1, 0.2, 0.6);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
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

    glColor3d(0.1, 0.2, 0.6);
    glVertex2i(900, 300);

    glColor3f(0.1, 0.2, 0.6);
    glVertex2i(800, 200);

    glColor3f(0.1, 0.2, 0.6);
    glVertex2i(900, 100);

    glColor3f(0.1, 0.2, 0.6);
    glVertex2i(1000, 200);
    glEnd();

    Cord[8][0] = 800;
    Cord[8][1] = 100;
    Cord[8][2] = 1000;
    Cord[8][3] = 300;
}

void Interface2()
{
    char title[] = "Box 'em Up";
    glColor3f(0.5, 0.0, 0.0);
    drawStrokeText(title, 275, 630, 5, 10, 0.67, 0.67);
    int temp = 1;

    if (size == 4) {
        yg = 60;
        xg = 80;
        xmax = 840;
        ymax = 600;
        total = 81;
        temp = 80;
    }
    if (size == 3) {
        yg = 65;
        xg = 85;
        ymax = 585;
        xmax = 765;
        total = 64;
        temp = 80;
    }
    if (size == 2) {
        yg = 70;
        xg = 95;
        xmax = 800;
        ymax = 600;
        total = 49;
        temp = 50;
    }
    if (size == 1) {
        yg = 80;
        ymax = 500;
        xg = 110;
        xmax = 660;
        total = 25;
    }

    // SIDE BOX
    int ytemp = 480 + temp;
    glColor3d(0.1, 0.5, 0.7);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(830, 80);
    glVertex2i(1070, 80);
    glVertex2i(1070, ytemp);
    glVertex2i(830, ytemp);
    glEnd();

    // SIDE BOX TEXT
    char str[] = "Names";
    glColor3f(0.0, 0.0, 0.0);
    drawStrokeText(str, 850, 450, 3, 5, 0.2, 0.2);

    char str1[] = "Scores";
    glColor3f(0.0, 0.0, 0.0);
    drawStrokeText(str1, 970, 450, 3, 6, 0.2, 0.2);






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

    glColor3f(0.1, 0.5, 0.7);

    if (player == 0) {
        glColor3f(1.0, 1.0, 1.0);

    }
    glBegin(GL_POINTS);
    glVertex2f(840, 410);
    glEnd();

    glColor3f(0.1, 0.5, 0.7);

    if (player == 1) {
        glColor3f(1.0, 1.0, 1.0);
    }

    glBegin(GL_POINTS);
    glVertex2f(840, 370);
    glEnd();

    glColor3f(0.1, 0.5, 0.7);

    if (player == 2) {
        glColor3f(1.0, 1.0, 1.0);
    }
    glBegin(GL_POINTS);
    glVertex2f(840, 330);
    glEnd();

    glColor3f(0.1, 0.5, 0.7);

    if (player == 3) {
        glColor3f(1.0, 1.0, 1.0);
    }
    glBegin(GL_POINTS);
    glVertex2f(840, 290);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);


    if (a < 15 && yi < ymax && xi < xmax && xi>xg && yi>yg) {
        if (a < b && a < xg - b) {
            x1 = xi - b;
            y1 = yi - a;
            x2 = x1 + xg;
            y2 = y1;
            fill = true;
            notyet = true;
        }

    }
    else if (a > 45 && yi < ymax && xi < xmax && xi>xg && yi>yg) {
        if (yg - a < b && yg - a < xg - b) {
            x1 = xi - b;
            y1 = yi - a + yg;
            x2 = x1 + xg;
            y2 = y1;
            fill = true;
            notyet = true;
        }

    }
    if (b < 20 && notyet == false && yi < ymax && xi < xmax && xi>xg && yi>yg) {
        if (b < a && b < yg - a) {
            x1 = xi - b;
            y1 = yi - a;
            x2 = x1;
            y2 = y1 + yg;
            fill = true;
        }

    }
    else if (b > yg && notyet == false && yi < ymax && xi < xmax && xi>xg && yi>yg) {
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



    /*
    if (q == total) {
        Set_Interface = 3;
    }
    */
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

    char str2[] = "Player1: ";

    glColor3f(1.0, 0.0, 0.0);
    drawStrokeText(str2, 850, 400, 2, 10, 0.2, 0.2);

    if (players > 1)
    {
        char str3[] = "Player2: ";
        glColor3f(0.0, 1.0, 0.0);
        drawStrokeText(str3, 850, 360, 2, 10, 0.2, 0.2);
        if (players > 2)
        {
            char str4[] = "Player3: ";
            glColor3f(0.0, 0.0, 1.0);
            drawStrokeText(str4, 850, 320, 2, 10, 0.2, 0.2);
            if (players > 3)
            {
                char str5[] = "Player4: ";
                glColor3f(0.8, 0.5, 0.8);
                drawStrokeText(str5, 850, 280, 2, 10, 0.2, 0.2);
            }
        }
    }

    char str6[2];
    tostring(str6, count[0]);

    char str7[3];
    tostring(str7, count[1]);

    char str8[3];
    tostring(str8, count[2]);

    char str9[4];
    tostring(str9, count[3]);

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.5, 0.7);
    glVertex2f(990, 270);
    glVertex2f(1030, 270);
    glVertex2f(1030, 430);
    glVertex2f(990, 430);
    glEnd();

    glColor3f(0.6, 0.8, 0.0);
    drawStrokeText(str6, 1000, 400, 2, 10, 0.2, 0.2);

    glColor3f(0.6, 0.8, 0.0);
    drawStrokeText(str7, 1000, 360, 2, 10, 0.2, 0.2);

    glColor3f(0.6, 0.8, 0.0);
    drawStrokeText(str8, 1000, 320, 2, 10, 0.2, 0.2);

    glColor3f(0.6, 0.8, 0.0);
    drawStrokeText(str9, 1000, 280, 2, 10, 0.2, 0.2);

    // ADD WINNER
    int i;
    // Finding max score
    int max = count[0];
    for (i = 0; i < 4; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }

    }
    if (q == total)
    {

        if (count[0] == max)
        {
            winy = 400;
        }
        if (count[1] == max)
        {
            winy = 360;
        }
        if (count[2] == max)
        {
            winy = 320;
        }
        if (count[3] == max)
        {
            winy = 280;
        }

        char w1[] = "W";
        glColor3f(1.0, 1.0, 0.0);
        drawStrokeText(w1, 820 - 7, winy, 5, 2, 0.2, 0.2);

        char w2[] = "W";
        glColor3f(1.0, 0.75, 0.0);
        drawStrokeText(w2, 820 - 7, winy, 3, 2, 0.2, 0.2);

    }

}

void Interface3()
{

    glClearColor(0.6, 0.8, 0.9, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(20.0);

    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2i(200, 350);
    glVertex2i(550, 350);
    glVertex2i(550, 50);
    glVertex2i(200, 50);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex2i(200, 550);
    glVertex2i(550, 550);
    glVertex2i(550, 400);
    glVertex2i(200, 400);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.8, 0.8, 0.8);
    glVertex2i(200, 300);
    glVertex2i(550, 300);
    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.7, 0.7, 0.7);
    glVertex2i(350, 350);
    glVertex2i(350, 50);
    glEnd();
    Interface3Text();
    Winner();

}

void Winner() {
    int i;

    int max = count[0];
    for (i = 0; i < 4; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }

    }

    // Winner Score
    char str13[3];
    tostring(str13, max);
    glColor3f(0.7, 0.8, 0.9);
    drawStrokeText(str13, 440, 450, 2, 2, 0.2, 0.2);
    if (count[0] == max)
    {
        char str11[] = "Player#01";
        glColor3f(1.0, 0.0, 0.0);
        drawStrokeText(str11, 400, 500, 2, 10, 0.2, 0.2);

    }
    else if (count[1] == max)
    {
        char str12[] = "Player#02";
        glColor3f(0.0, 1.0, 0.0);
        drawStrokeText(str12, 400, 500, 2, 10, 0.2, 0.2);
    }
    else if (count[2] == max)
    {
        char str13[] = "Player#03";
        glColor3f(0.0, 0.0, 1.0);
        drawStrokeText(str13, 400, 500, 2, 10, 0.2, 0.2);

    }
    else if (count[3] == max)
    {
        char str14[] = "Player#04";
        glColor3f(0.8, 0.5, 0.8);
        drawStrokeText(str14, 400, 500, 2, 10, 0.2, 0.2);
    }
}

void tostring(char str[], int num)
{
    int i, rem, len = 0;
    f = num;
    while (f != 0)
    {
        len++;
        f /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }

}

void Interface3Text()
{
    //converting the scores into string
    char str6[2];
    tostring(str6, count[0]);

    char str7[3];
    tostring(str7, count[1]);

    char str8[3];
    tostring(str8, count[2]);

    char str9[4];
    tostring(str9, count[3]);

    char str[] = "Names";
    glColor3f(0.0, 0.0, 0.0);
    drawStrokeText(str, 225, 320, 3, 5, 0.2, 0.2);

    char str1[] = "Scores";
    glColor3f(0.0, 0.0, 0.0);
    drawStrokeText(str1, 400, 320, 3, 6, 0.2, 0.2);

    char str2[] = "Player1";
    glColor3f(1.0, 0.0, 0.0);
    drawStrokeText(str2, 225, 250, 3, 10, 0.2, 0.2);

    char str3[] = "Player2";
    glColor3f(0.0, 1.0, 0.0);
    drawStrokeText(str3, 225, 200, 3, 10, 0.2, 0.2);

    char str4[] = "Player3";
    glColor3f(0.0, 0.0, 1.0);
    drawStrokeText(str4, 225, 150, 3, 10, 0.2, 0.2);

    char str5[] = "Player4";
    glColor3f(0.8, 0.5, 0.8);
    drawStrokeText(str5, 225, 100, 3, 10, 0.2, 0.2);

    char str10[] = "WinnerName:";
    glColor3f(0.1, 0.6, 0.6);
    drawStrokeText(str10, 225, 500, 3, 15, 0.2, 0.2);

    char str11[] = "WinnerScore:";
    glColor3f(0.1, 0.6, 0.6);
    drawStrokeText(str11, 225, 450, 3, 15, 0.2, 0.2);



    //Displaying all the scores
    glColor3f(1.0, 0.0, 0.0);
    drawStrokeText(str6, 430, 250, 3, 2, 0.2, 0.2);

    glColor3f(0.0, 1.0, 0.0);
    drawStrokeText(str7, 430, 200, 3, 2, 0.2, 0.2);

    glColor3f(0.0, 0.8, 1.0);
    drawStrokeText(str8, 430, 150, 3, 2, 0.2, 0.2);

    glColor3f(0.8, 0.5, 0.8);
    drawStrokeText(str9, 430, 100, 3, 2, 0.2, 0.2);
}