#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

void draw(bool **array, int n, int row, int col) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            array[row-i][col-j] = true;
            array[row-i][col+j] = true;
        }
        array[row-i][col+n] = true;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            array[row+i][col+j] = true;
            array[row+i][col-j+1] = true;
        }
    }
}

void calculateDraw(bool **array, int n, int row, int col) {
    draw(array, n>>1, row, col);
    if (n > 2) {
        calculateDraw(array, n>>1, row-(n>>1), col-(n>>1));
        calculateDraw(array, n>>1, row+(n>>1), col-(n>>1));
        calculateDraw(array, n>>1, row+(n>>1), col+(n>>1));
        calculateDraw(array, n>>1, row-(n>>1), col+(n>>1));
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int arraySize = 0;
    for (int i = 0; i < log2(n); ++i) {
        arraySize += pow(2, i);
    }
    arraySize *= 2;
    arraySize += n;
    bool **array = (bool **)calloc(sizeof(bool*),arraySize+1);
    for (int i = 0; i <= arraySize; ++i) {
        array[i] = (bool *)calloc(sizeof(bool), arraySize+1);
    }
    //draw(array, n>>1, arraySize>>1, arraySize>>1);
    calculateDraw(array, n, arraySize>>1, arraySize>>1);
    for (int i = 0; i <= arraySize; ++i) {
        for (int j = 0; j <= arraySize; ++j) {
            if (array[i][j]) {
                printf("X");
            }
            else printf(" ");
        }
        printf("\n");
    }
    //printf("%d",arraySize);
} 