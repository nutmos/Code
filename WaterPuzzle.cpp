#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

int **table;

int minTimes = INT_MAX;
int n1,n2,n3,n4;

void waterPuzzle(int n1, int n2, int times) {
    ++times;
    //printf("times = %d\n",times);
    if (n1 == n3 && n2 == n4) {
        minTimes = min(times, minTimes);
    }
    if (!table[5][n2]) {
        table[5][n2] = true;
        waterPuzzle(5, n2,times);
    }
    if (!table[n1][3]) {
        table[n1][3] = true;
        waterPuzzle(n1, 3,times);
    }
    if (!table[n1][0]) {
        table[n1][0] = true;
        waterPuzzle(n1, 0,times);
    }
    if (!table[0][n2]) {
        table[0][n2] = true;
        waterPuzzle(0, n2,times);
    }
    if (5-n1 >= 0 && n2-5+n1 >= 0) {
        if (!table[5-n1][n2-5+n1]) {
            table[5-n1][n2-5+n1] = true;
            waterPuzzle(5-n1, n2-5+n1,times);
        }
    }
    if (n1-3+n2 >= 0 && 3-n2 >= 0) {
        if (!table[n1-3+n2][3-n2]) {
            table[n1-3+n2][3-n2] = true;
            waterPuzzle(n1-3+n2, 3-n2,times);
        }
    }
}

int main() {
    scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
    table = new int*[6];
    table[0] = (int *)calloc(sizeof(int), 4);
    table[1] = (int *)calloc(sizeof(int), 4);
    table[2] = (int *)calloc(sizeof(int), 4);
    table[3] = (int *)calloc(sizeof(int), 4);
    table[4] = (int *)calloc(sizeof(int), 4);
    table[5] = (int *)calloc(sizeof(int), 4);
    table[n1][n2] = true;
    waterPuzzle(n1, n2,0);
    printf("%d",--minTimes);
}