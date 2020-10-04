void Interface2() {
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