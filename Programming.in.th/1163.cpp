//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
//First compile with Xcode 4.6.1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int p = pow(2,n);
    int **spaceStation = (int**)calloc(sizeof(int*), p);
    for (int j = 0; j < p; j++) {
        spaceStation[j] = (int*)calloc(sizeof(int), n);
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < n; j++) {
            printf("%d",spaceStation[i][j]);
        }
        printf(" ");
        for (int j = 0; j < n; j++) {
            if (j == i) printf("1");
            else printf("%d",spaceStation[i][j]);
        }
        printf("\n");
    }
    for (int i = 1; i < p; i++) {
        //printf("test\n");
        spaceStation[i][n-1]++;
        if (spaceStation[i][n-1] == 2) {
            for (int j = n-1; j > 0; --j) {
                if (spaceStation[i][j] == 2) {
                    spaceStation[i][j-1]++;
                    spaceStation[i][j] = 0;
                }
            }
        }
        if (i != p-1) {
            for (int j = 0; j < n; j++) {
                spaceStation[i+1][j] = spaceStation[i][j];
            }
        }
        /*printf("i = %d\n",i);
        for (int j = 0; j < n; j++) {
            printf("%d",spaceStation[i][j]);
        }
        printf("\n");*/
        for (int j = n-1; j >= 0; --j) {
            //printf("j = %d\n",j);
            if (spaceStation[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    printf("%d",spaceStation[i][k]);
                }
                printf(" ");
                for (int k = 0; k < n; k++) {
                    if (k == j) printf("%d",1);
                    else printf("%d",spaceStation[i][k]);
                }
                printf("\n");
            }
        }
    }
}