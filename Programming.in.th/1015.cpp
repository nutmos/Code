#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int area;
int **tile;
int n;
int tmp;

void calculateArea(int row, int col) {
    if (tile[row][col] == tmp) {
        ++area;
        tile[row][col] = 0;
        if (row-1 >= 0) {
            calculateArea(row-1, col);
        }
        if (row+1 < n) {
            calculateArea(row+1, col);
        }
        if (col-1 >= 0) {
            calculateArea(row, col-1);
        }
        if (col+1 < n) {
            calculateArea(row, col+1);
        }
    }
}

int main() {
    scanf("%d",&n);
    tile = new int*[n];
    for (int i = 0; i < n; ++i) {
        tile[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d",&tile[i][j]);
        }
    }
    int correctCount = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tile[i][j] != 0) {
                area = 0;
                tmp = tile[i][j];
                int tmpTile[8] = {(j+1 < n)?tile[i][j+1]:0,
                    (j+2 < n)?tile[i][j+2]:0,
                    (j-1 >= 0)?tile[i][j-1]:0,
                    (j-2 >= 0)?tile[i][j-2]:0,
                    (i-1 >= 0)?tile[i-1][j]:0,
                    (i-2 >= 0)?tile[i-2][j]:0,
                    (i+1 < n)?tile[i+1][j]:0,
                    (i+2 < n)?tile[i+2][j]:0};
                calculateArea(i, j);
                if (area == 3) {
                    if (tmpTile[0] == tmp) {
                        if (tmpTile[1] != tmp && tmpTile[2] != tmp) {
                            ++correctCount;
                        }
                    }
                    else if (tmpTile[2] == tmp) {
                        if (tmpTile[3] != tmp) {
                            ++correctCount;
                        }
                    }
                    else if (tmpTile[4] == tmp) {
                        if (tmpTile[5] != tmp && tmpTile[6] != tmp) {
                            ++correctCount;
                        }
                    }
                    else if (tmpTile[6] == tmp) {
                        if (tmpTile[7] != tmp) {
                            ++correctCount;
                        }
                    }
                }
                //printf("area = %d ",area);
            }
        }
        //printf("\n");
    }
    printf("%d",correctCount);
}