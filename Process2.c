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