#include <iostream>
#include <conio.h>
using namespace std;

int main() {

    char arr[10][10];

    int x = 0, y = 0;

    srand(time(0));

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            arr[i][j] = '.';

    arr[x][y] = 'P';

    int say = 0;

    while (say < 2) {
        int r = rand() % 10;
        int c = rand() % 10;

        if (arr[r][c] == '.' && !(r == x && c == y)) {
            arr[r][c] = 'B';
            say++;
        }
    }

    while (true) {

        system("cls");

        cout << "========== GAME ==========\n";
        cout << "MOVE: ARROW KEYS\n";
        cout << "P = Player | B = Box\n";
        cout << "==========================\n\n";

        for (int i = 0; i < 10; i++) {
            cout << "| ";
            for (int j = 0; j < 10; j++) {
                cout << arr[i][j] << " ";
            }
            cout << "|\n";
        }

        int key = _getch();

        int newX = x;
        int newY = y;

        if (key == 224) {
            key = _getch();

            if (key == 72) newX--;
            else if (key == 80) newX++;
            else if (key == 75) newY--;
            else if (key == 77) newY++;
        }

        if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {

            if (arr[newX][newY] == 'B') {

                int bx = newX + (newX - x);
                int by = newY + (newY - y);

                if (bx >= 0 && bx < 10 && by >= 0 && by < 10 && arr[bx][by] == '.') {

                    arr[bx][by] = 'B';
                    arr[newX][newY] = 'P';
                    arr[x][y] = '.';

                    x = newX;
                    y = newY;
                }
            }
            else if (arr[newX][newY] == '.') {

                arr[x][y] = '.';
                x = newX;
                y = newY;
                arr[x][y] = 'P';
            }
        }
    }
}