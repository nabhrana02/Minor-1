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
