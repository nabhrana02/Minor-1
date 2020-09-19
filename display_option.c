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
