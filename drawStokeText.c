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
