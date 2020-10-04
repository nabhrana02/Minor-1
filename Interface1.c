void Interface1() {

    //COORDINATES ORDER:   Top Left --> Bottom Left --> Bottom Right --> Top Right
    /*
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
    glColor3d(0.0, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_POLYGON);
    glVertex2i(60, 500);
    glVertex2i(60, 400);
    glVertex2i(735, 400);
    glVertex2i(735, 500);
    glEnd();

    // 'GRID: ' BOX
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
    glVertex2i(85, 493);
    glVertex2i(85, 407);
    glVertex2i(200, 407);
    glVertex2i(200, 493);
    glEnd();
    */
    // GRID OPTIONS' BOXES
    glLineWidth(3);
    // OPTION NO. #01
    glColor3d(0.0, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
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
    glColor3d(0.0, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
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
    glColor3d(0.0, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
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
    glColor3d(0.0, 0.0, 0.0);// Set line segment color as glColor3f(R,G,B)
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
    // "PLAYERS" TITLE
    glColor3d(1.0, 1.0, 1.0);// Set line segment color as glColor3f(R,G,B)
    glBegin(GL_LINE_LOOP);
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

    glColor3d(0.1, 0.1, 0.1);
    glVertex2i(900, 350);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(800, 250);

    glColor3f(0.3, 0.3, 0.3);
    glVertex2i(900, 150);

    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(1000, 250);
    glEnd();

    Cord[8][0] = 800;
    Cord[8][1] = 150;
    Cord[8][2] = 1000;
    Cord[8][3] = 350;
}