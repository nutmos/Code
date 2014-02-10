#include <iostream>
#include <cstdio>
#include <cstdlib>
#define UNDIS 0
#define DIS 1

using namespace std;

char *name;

bool *status;

int findName(char ch, int n) {
    for (int i = 0; i < n; ++i) {
        if (name[i] == ch) {
            return i;
        }
    }
    return -1;
}

void dfs(int **matrix, int node, int n) {
    status[node] = DIS;
    for (int i = 0; i < n; ++i) {
        if (matrix[node][i] != 0 && status[i] == UNDIS) {
            dfs(matrix, i, n);
        }
    }
}

bool isAllDis(int n) {
    for (int i = 0; i < n; ++i) {
        if (status[i] == UNDIS) {
            return false;
        }
    }
    return true;
}

int main() {
    //int testcase;
    //scanf("%d",&testcase);
    //for (int II = 0; II < testcase; ++II) {
        int n,m;
        scanf("%d %d",&n,&m);
        int **matrix;
        matrix = (int **)calloc(sizeof(int *), n);
        name = (char *)calloc(sizeof(char), n);
        char str[2];
        for (int i = 0; i < n; ++i) {
            matrix[i] = (int *)calloc(sizeof(int), n);
            scanf("%s",str);
            name[i] = str[0];
        }
        char from[2],to[2];
        for (int i = 0; i < m; ++i) {
            scanf("%s %s",from,to);
            int fromNum = findName(from[0], n);
            int toNum = findName(to[0], n);
            matrix[fromNum][toNum] = 1;
            matrix[toNum][fromNum] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            status = (bool *)calloc(sizeof(bool), n);
            status[i] = DIS;
            if (i == 0) {
                dfs(matrix, 1, n);
            }
            else {
                dfs(matrix, 0, n);
            }
            if (!isAllDis(n)) {
                //printf("node %d\n",i);
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 1) {
                        matrix[i][j] = 2;
                        matrix[j][i] = 2;
                        ++ans;
                    }
                }
                //++ans;
            }
            free(status);
        }
        /*for (int i = 0; i < n; ++i) {
         for (int j = 0; j < n; ++j) {
         printf("%d ",matrix[i][j]);
         }
         printf("\n");
         }*/
        printf("%d\n",ans);
    //}
}