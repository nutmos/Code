#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#define DIS 1
#define UNDIS 0

using namespace std;

int n,m;
int **apple;
int **ans;
bool **status;

struct matrix {
    int row, col;
};

int main() {
    scanf("%d %d",&n,&m);
    apple = new int*[n];
    ans = new int*[n];
    status = new bool*[n];
    for (int i = 0; i < n; ++i) {
        ans[i] = (int *)calloc(sizeof(int), m);
        status[i] = (bool *)calloc(sizeof(bool), m);
        apple[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            scanf("%d",&apple[i][j]);
        }
    }
    queue<matrix> Q;
    ans[0][0] = apple[0][0];
    Q.push({1,0});
    ans[1][0] = apple[1][0] + ans[0][0];
    Q.push({0,1});
    ans[0][1] = apple[0][1] + ans[0][0];
    while (!Q.empty()) {
        matrix process = Q.front();
        if (process.row != n-1) {
            ans[process.row+1][process.col] = max(ans[process.row+1][process.col], ans[process.row][process.col] + apple[process.row+1][process.col]);
            if (status[process.row+1][process.col] != DIS) {
                Q.push({process.row+1, process.col});
                status[process.row+1][process.col] = DIS;
            }
        }
        if (process.col != m-1) {
            ans[process.row][process.col+1] = max(ans[process.row][process.col+1], ans[process.row][process.col] + apple[process.row][process.col+1]);
            if (status[process.row][process.col+1] != DIS) {
                Q.push({process.row, process.col+1});
                status[process.row][process.col+1] = DIS;
            }
        }
        Q.pop();
    }
    printf("%d",ans[n-1][m-1]);
}