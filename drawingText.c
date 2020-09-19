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
