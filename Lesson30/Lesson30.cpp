#include <iostream>
#include <conio.h>
#include "models.h"

using namespace std;

int main() {

    srand(time(0));

    char room[10][10];

    Player p(0, 0);

    Box b1(rand() % 8 + 1, rand() % 8 + 1);
    Box b2(rand() % 8 + 1, rand() % 8 + 1);

    while (true) {

        system("cls");

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                room[i][j] = '0';
            }
        }

        room[p.x][p.y] = '#';
        room[b1.x][b1.y] = '*';
        room[b2.x][b2.y] = '*';

        cout << "[ Qutu 1 ] -> "
            << (b1.inCorner ? "Kuncde" : "Kuncde deyil") << endl;

        cout << "[ Qutu 2 ] -> "
            << (b2.inCorner ? "Kuncde" : "Kuncde deyil") << endl;

        cout << "------------------------" << endl;

        for (int i = 0; i < 10; i++) {

            for (int j = 0; j < 10; j++) {
                cout << room[i][j] << " ";
            }

            cout << endl;
        }

        int key = _getch();

        int nextX = p.x;
        int nextY = p.y;
       
        if (key == 224) {

            key = _getch();

            if (key == 72) nextX--;
            else if (key == 80) nextX++;
            else if (key == 75) nextY--;
            else if (key == 77) nextY++;
        }

        if (nextX >= 0 && nextX < 10 &&
            nextY >= 0 && nextY < 10) {

            if (nextX == b1.x && nextY == b1.y) {

                int boxNextX = b1.x + (b1.x - p.x);
                int boxNextY = b1.y + (b1.y - p.y);

                if (boxNextX >= 0 && boxNextX < 10 &&
                    boxNextY >= 0 && boxNextY < 10) {

                    b1.x = boxNextX;
                    b1.y = boxNextY;

                    p.x = nextX;
                    p.y = nextY;

                    b1.checkCorner();
                }
            }

            else if (nextX == b2.x && nextY == b2.y) {

                int boxNextX = b2.x + (b2.x - p.x);
                int boxNextY = b2.y + (b2.y - p.y);

                if (boxNextX >= 0 && boxNextX < 10 &&
                    boxNextY >= 0 && boxNextY < 10) {

                    b2.x = boxNextX;
                    b2.y = boxNextY;

                    p.x = nextX;
                    p.y = nextY;

                    b2.checkCorner();
                }
            }

            else {

                p.x = nextX;
                p.y = nextY;
            }
        }
    }

    return 0;
}