#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <climits>
#include <queue>

using namespace std;

struct matrix {
    int row,col;
};

int **maze;
int **path;
matrix begin, end;
int m,n;

void printPath() {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
}

void makePath() {
    path = new int*[m];
    for (int i = 0; i < m; ++i) {
        path[i] = (int *)calloc(sizeof(int), n);
    }
    path[begin.row][begin.col] = 1;
}

void clearPath() {
    for (int i = 0; i < m; ++i) {
        delete [] path[i];
    }
    delete [] path;
}

int main() {
    scanf("%d %d",&m,&n);
    scanf("%d %d %d %d",&begin.row,&begin.col,&end.row,&end.col);
    --begin.row; --begin.col; --end.row; --end.col;
    list<matrix> wall;
    maze = new int*[m];
    for (int i = 0; i < m; ++i) {
        maze[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d",&maze[i][j]);
            if (maze[i][j] == 0) {
                wall.push_back({i,j});
            }
        }
    }
    queue<matrix> q;
    int count = 0, shortestPath = INT_MAX;
    for (list<matrix>::iterator it = wall.begin(); it != wall.end(); ++it) {
        maze[it->row][it->col] = 1;
        makePath();
        q.push(begin);
        while (!q.empty()) {
            //printf("test\n");
            matrix process;
            process = q.front();
            q.pop();
            if (process.row != 0) {
                if (maze[process.row-1][process.col] == 1) {
                    if (path[process.row-1][process.col] == 0) {
                        q.push({process.row-1,process.col});
                        path[process.row-1][process.col] = path[process.row][process.col] + 1;
                    }
                    else path[process.row-1][process.col] = min(path[process.row][process.col] + 1, path[process.row-1][process.col]);
                }
            }
            if (process.row != m-1) {
                if (maze[process.row+1][process.col] == 1) {
                    if (path[process.row+1][process.col] == 0) {
                        q.push({process.row+1, process.col});
                        path[process.row+1][process.col] = path[process.row][process.col] + 1;
                    }
                    else path[process.row+1][process.col] = min(path[process.row][process.col] + 1, path[process.row+1][process.col]);
                }
            }
            if (process.col != 0) {
                if (maze[process.row][process.col-1] == 1) {
                    if (path[process.row][process.col-1] == 0) {
                        q.push({process.row, process.col-1});
                        path[process.row][process.col-1] = path[process.row][process.col] + 1;
                    }
                    else path[process.row][process.col-1] = min(path[process.row][process.col] + 1, path   [process.row][process.col-1]);
                }
            }
            if (process.col != n-1) {
                if (maze[process.row][process.col+1] == 1) {
                    if (path[process.row][process.col+1] == 0) {
                        q.push({process.row, process.col+1});
                        path[process.row][process.col+1] = path[process.row][process.col] + 1;
                    }
                    else path[process.row][process.col+1] = min(path[process.row][process.col] + 1, path   [process.row][process.col+1]);
                }
            }
        }
        if (path[end.row][end.col] != 0) {
            //printf("test\n");
            ++count;
            shortestPath = min(path[end.row][end.col], shortestPath);
        }
        //printPath();
        clearPath();
        maze[it->row][it->col] = 0;
    }
    printf("%d\n%d",count,shortestPath);
}