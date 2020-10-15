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
    char playernumber[][10] = { "1 Player", "2 players", "3 players", "4 players" };


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
    glColor3d(0.6, 0.8, 0.9);
    drawStrokeText(str3, 820, 180, 7, 5, 0.4, 0.4);


}