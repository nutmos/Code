#include <iostream>

using namespace std;

struct ballPosition {
    int x;
    int y;
};

struct fieldElement {
    int direction;
    int mark;
};

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    struct fieldElement field[m][n];
    for (register int i = 0; i < m; i++) {
        for (register int j = 0; j < n; j++) {
            cin >> field[i][j].direction;
        }
    }
    struct ballPosition ball[k];
    for (register int i = 0; i < k; i++) {
        cin >> ball[i].x >> ball[i].y;
    }
    for (register int i = 0; i < k; i++) {
        for (register int i = 0; i < m; i++) {
            for (register int j = 0; j < n; j++) {
                field[i][j].mark = 0;
            }
        }
        int xTemp = --ball[i].x, yTemp = --ball[i].y;
        while (1) {
            field[yTemp][xTemp].mark = 1;
            switch (field[yTemp][xTemp].direction) {
                case 1:
                    yTemp--;
                    break;
                case 2:
                    xTemp++;
                    break;
                case 3:
                    yTemp++;
                    break;
                case 4:
                    xTemp--;
                    break;
                default:
                    break;
            }
            /*for (register int i = 0; i < m; i++) {
                for (register int j = 0; j < n; j++) {
                    cout << field[i][j].mark << ' ';
                }
                cout << endl;
            }
            cout << "xTemp = " << xTemp << " yTemp = " << yTemp << endl;
            cout << endl;*/
            if (xTemp == -1) {
                cout << "W" << endl;
                break;
            }
            else if (xTemp == n) {
                cout << "E" << endl;
                break;
            }
            else if (yTemp == -1) {
                cout << "N" << endl;
                break;
            }
            else if (yTemp == m) {
                cout << "S" << endl;
                break;
            }
            if (field[yTemp][xTemp].mark) {
                cout << "NO" << endl;
                break;
            }
        }
    }
    return 0;
}