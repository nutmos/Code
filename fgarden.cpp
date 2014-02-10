#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,m;
char **flowerPlot;

int maxSpace = 0;

int area;

void calculateArea(int row, int col) {
    if (flowerPlot[row][col] != '.') {
        return;
    }
    ++area;
    flowerPlot[row][col] = 'F';
    if (row == 0) {
        if (col == 0) {
            calculateArea(row+1, col);
            calculateArea(row, col+1);
        }
        else if (col == m-1) {
            calculateArea(row+1, col);
            calculateArea(row, col-1);
        }
        else {
            calculateArea(row+1, col);
            calculateArea(row, col+1);
            calculateArea(row, col-1);
        }
    }
    else if (row == n-1) {
        if (col == 0) {
            calculateArea(row-1, col);
            calculateArea(row, col+1);
        }
        else if (col == m-1) {
            calculateArea(row-1, col);
            calculateArea(row, col-1);
        }
        else {
            calculateArea(row-1, col);
            calculateArea(row, col+1);
            calculateArea(row, col-1);
        }
    }
    else {
        if (col == 0) {
            calculateArea(row+1, col);
            calculateArea(row-1, col);
            calculateArea(row, col+1);
        }
        else if (col == m-1) {
            calculateArea(row+1, col);
            calculateArea(row-1, col);
            calculateArea(row, col-1);
        }
        else {
            calculateArea(row+1, col);
            calculateArea(row-1, col);
            calculateArea(row, col+1);
            calculateArea(row, col-1);
        }
    }
}

int main() {
    scanf("%d %d",&n,&m);
    flowerPlot = new char*[n];
    for (int i = 0; i < n; ++i) {
        flowerPlot[i] = new char[m+1];
        scanf("%s",flowerPlot[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (flowerPlot[i][j] == '#') {
                if (i == 0) {
                    if (j == 0) {
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                    }
                    else if (j == m-1) {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                        }
                    else {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                    }
                }
                else if (i == n-1) {
                    if (j == 0) {
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                    else if (j == m-1) {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                    else {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                }
                else {
                    if (j == 0) {
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                    else if (j == m-1) {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                    else {
                        if (flowerPlot[i][j-1] == '.') flowerPlot[i][j-1] = 'R';
                        if (flowerPlot[i][j+1] == '.') flowerPlot[i][j+1] = 'R';
                        if (flowerPlot[i+1][j] == '.') flowerPlot[i+1][j] = 'R';
                        if (flowerPlot[i-1][j] == '.') flowerPlot[i-1][j] = 'R';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (flowerPlot[i][j] == '.') {
                area = 0;
                calculateArea(i,j);
                if (area > maxSpace) {
                    maxSpace = area;
                }
            }
        }
    }
    printf("%d",maxSpace);
}