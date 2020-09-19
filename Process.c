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

    if (xi > Cord[8][0] && xi < Cord[8][2] && yi > Cord[8][1] && yi < Cord[8][3]) {
        Set_Interface = 2;

    }
}