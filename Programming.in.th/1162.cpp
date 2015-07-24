#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int n,m,t;
    scanf("%d %d %d",&m,&n,&t);
    int tmp;
    int **way = new int*[t+1];
    bool **haveObject = new bool*[t+1];
    haveObject[0] = (bool *)calloc(sizeof(bool), m+1);
    for (int i = 1; i <= t; ++i) {
        haveObject[i] = new bool[m+1];
        way[i] = (int *)calloc(sizeof(int), m+1);
        for (int j = 1; j <= m; ++j) {
            scanf("%d",&tmp);
            haveObject[i][j] = tmp > 0;
        }
    }
    /*for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",haveObject[i][j]);
        }
        printf("\n");
    }*/
    if (!haveObject[1][n]) {
        way[1][n] = n;
    }
    if (n-1 > 0) {
        if (!haveObject[1][n-1]) {
            way[1][n-1] = n;
        }
    }
    if (n+1 <= m) {
        if (!haveObject[1][n+1]) {
            way[1][n+1] = n;
        }
    }
    vector<int> v;
    for (int i = 1; i < t; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (way[i][j] != 0) {
                if (j-1 > 0) {
                    if (!haveObject[i+1][j-1]) {
                        way[i+1][j-1] = j;
                    }
                }
                if (!haveObject[i+1][j]) {
                    way[i+1][j] = j;
                }
                if (j+1 <= m) {
                    if (!haveObject[i+1][j+1]) {
                        //printf("i+1 = %d, j+1 = %d\n",i+1,j+1);
                        way[i+1][j+1] = j;
                    }
                }
            }
        }
    }
    /*for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d ",way[i][j]);
        }
        printf("\n");
    }*/
    int before;
    int rowBefore;
    for (int i = 1; i <= m; ++i) {
        if (way[t][i] != 0) {
            before = way[t][i];
            rowBefore = i;
        }
    }
    //printf("before = %d, rowBefore = %d\n",before, rowBefore);
    for (int i = t-1; i > 0; --i) {
        if (before == rowBefore) {
            v.push_back(3);
        }
        else if (before == rowBefore+1) {
            rowBefore += 1;
            v.push_back(1);
        }
        else {
            rowBefore -= 1;
            v.push_back(2);
        }
        before = way[i][before];
        //printf("before = %d, rowBefore = %d\n",before, rowBefore);
    }
    if (before > rowBefore) {
        v.push_back(1);
    }
    else if (before < rowBefore) {
        v.push_back(2);
    }
    else {
        v.push_back(3);
    }
    for (int i = (int)v.size() - 1; i >= 0; --i) {
        printf("%d\n",v[i]);
    }
}