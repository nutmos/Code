#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct coordinate {
    int row;
    int col;
};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    char walk[m][5];
    char tmp[2];
    int **table = new int*[n+1];
    for (int i = 0; i <= n; ++i) {
        table[i] = new int[n+1];
    }
    table[1][n] = 1;
    table[n][n] = 2;
    table[n][1] = 3;
    table[1][1] = 4;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%s",tmp);
            walk[j][i] = tmp[0];
        }
    }
    coordinate competitorAt[5] = {{0, 0}, {1, n}, {n, n}, {n, 1}, {1, 1}};
    int *competitor = (int *)calloc(sizeof(int), 5);
    competitor[1] = 1;
    competitor[2] = 1;
    competitor[3] = 1;
    competitor[4] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= 4; ++j) {
            coordinate at = {competitorAt[j].row, competitorAt[j].col};
            int beforeInTable;
            //printf("%c\n",walk[i][j]);
            if (walk[i][j] == 'N') {
                at.row -= 1;
            }
            else if (walk[i][j] == 'S') {
                at.row += 1;
            }
            else if (walk[i][j] == 'E') {
                at.col += 1;
            }
            else if (walk[i][j] == 'W') {
                at.col -= 1;
            }
            //printf("%d %d %d\n",j,at.row,at.col);
            if (at.row > 0 && at.row <= n && at.col > 0 && at.col <= n) {
                //printf("test\n");
                beforeInTable = table[at.row][at.col];
                if (beforeInTable == 0) {
                    table[at.row][at.col] = j;
                    ++competitor[j];
                    competitorAt[j].row = at.row;
                    competitorAt[j].col = at.col;
                }
                else {
                    if (competitorAt[beforeInTable].row == at.row && competitorAt[beforeInTable].col == at.col) {
                        //do nothing
                    }
                    else {
                        table[at.row][at.col] = j;
                        --competitor[beforeInTable];
                        competitorAt[j].row = at.row;
                        competitorAt[j].col = at.col;
                        ++competitor[j];
                        //printf("%d %d %d\n",j,competitorAt[j].row,competitorAt[j].col);
                    }
                }
            }
        }
    }
    /*for (int i = 1; i <= n; ++i) {
     for (int j = 1; j <= n; ++j) {
     printf("%d ",table[i][j]);
     }
     printf("\n");
     }*/
    int max = 0;
    for (int i = 1; i <= 4; ++i) {
        if (competitor[i] > max) {
            max = competitor[i];
        }
        //printf("competitor[%d] = %d\n",i,competitor[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (table[i][j] == 0) {
                printf("No");
                return 0;
            }
        }
    }
    int count = 0;
    for (int i = 1; i <= 4; ++i) {
        if (competitor[i] == max) {
            ++count;
        }
    }
    printf("%d %d\n",count,max);
    for (int i = 1; i <= 4; ++i) {
        if (competitor[i] == max) printf("%d\n",i);
    }
}