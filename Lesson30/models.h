#pragma once

class Player {

public:

    int x;
    int y;

    Player(int startX, int startY) {

        x = startX;
        y = startY;
    }
};

class Box {

public:

    int x;
    int y;

    bool inCorner;

    Box(int startX, int startY) {

        x = startX;
        y = startY;

        inCorner = false;
    }

    void checkCorner() {

        if ((x == 0 && y == 0) ||
            (x == 0 && y == 9) ||
            (x == 9 && y == 0) ||
            (x == 9 && y == 9)) 
        {

            inCorner = true;
        }
        else
        {
            inCorner = false;
        }
    }
};