//Copyright 2013 Nutmos' Studio
//All Right Reserved
//First Compile with Xcode 4.6
#include <iostream>
#include <cstdlib>

using namespace std;

int max_temp(int **temp, int x, int y, int m) {
    int maxArray[4] = {-6, -6, -6, -6};
    int maxNumber = -6;
    int markNumber = 0;
    //cout << "x = " << x << " y = " << y << " temp[x][y] = " << temp[y-1][x-1] << endl;
    //left
    if (x-2 >= 0) {
        markNumber++;
        //cout << "left" << endl;
        if (temp[y-1][x-2] > temp[y-1][x-1]) {
            maxArray[0] = max_temp(temp, x-1, y, m);
        }
        else {
            maxArray[0] = temp[y-1][x-1];
        }
    }
    //right
    if (x < m) {
        markNumber++;
        //cout << "right" << endl;
        if (temp[y-1][x] > temp[y-1][x-1]) {
            maxArray[1] = max_temp(temp, x+1, y, m);
        }
        else {
            maxArray[1] = temp[y-1][x-1];
        }
    }
    //up
    if (y-2 >= 0) {
        markNumber++;
        //cout << "up" << endl;
        if (temp[y-2][x-1] > temp[y-1][x-1]) {
            maxArray[2] = max_temp(temp, x, y-1, m);
        }
        else {
            maxArray[2] = temp[y-1][x-1];
        }
    }
    //down
    if (y < m) {
        markNumber++;
        //cout << "left" << endl;
        if (temp[y][x-1] > temp[y-1][x-1]) {
            maxArray[3] = max_temp(temp, x, y+1, m);
        }
        else {
            maxArray[3] = temp[y-1][x-1];
        }
    }
    if (markNumber == 0) {
        return temp[x-1][y-1];
    }
    for (register int i = 0; i < 4; i++) {
        if (maxNumber < maxArray[i]) {
            maxNumber = maxArray[i];
        }
    }
    //cout << "maxNumber = " << maxNumber << endl;
    return maxNumber;
}

int main() {
    int m,x,y;
    cin >> m;
    cin >> x >> y;
    int **temp = (int **)malloc(sizeof(int *) * m);
    for (register int i = 0; i < m; i++) {
        temp[i] = (int *)malloc(sizeof(int) * m);
    }
    for (register int i = 0; i < m; i++) {
        for (register int j = 0; j < m; j++) {
            cin >> temp[i][j];
            if (temp[i][j] == 100) temp[i][j] = -6;
        }
    }
    int max = max_temp(temp, x, y, m);
    cout << max;
}