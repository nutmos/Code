#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#define DIS 1
#define UNDIS 0

using namespace std;

char *name;
int *status;
int *dist;

int findName(char ch, int n) {
    for (int i = 0; i < n; ++i) {
        if (name[i] == ch) {
            return i;
        }
    }
    return -1;
}

int *connectedComponent;
int runner;

void findComponent(int **matrix, int n, int node) {
    connectedComponent[runner++] = node;
    status[node] = DIS;
    for (int i = 0; i < n; ++i) {
        if (matrix[node][i] != 0 && status[i] != DIS) {
            findComponent(matrix, n, i);
        }
    }
}
int *statusTmp;

void findShortestPath(int **matrix, int n, int node) {
    statusTmp[node] = DIS;
    for (int i = 0; i < n; ++i) {
        if (matrix[node][i] != 0 && dist[i] > matrix[node][i] + dist[node]) {
            dist[i] = matrix[node][i] + dist[node];
            findShortestPath(matrix, n, i);
        }
    }
}

int main() {
    //int testcase;
    //scanf("%d",&testcase);
    //for (int II = 0; II < testcase; ++II) {
        int n,r;
        scanf("%d %d",&n,&r);
        int **matrix = (int **)calloc(sizeof(int *), n);
        status = (int *)calloc(sizeof(int), n);
        name = (char *)calloc(sizeof(char), n);
        char str[2];
        for (int i = 0; i < n; ++i) {
            matrix[i] = (int *)calloc(sizeof(int), n);
            scanf("%s",str);
            name[i] = str[0];
        }
        char from[2],to[2];
        int weight;
        for (int i = 0; i < r; ++i) {
            scanf("%s %s %d",from,to,&weight);
            int fromNum = findName(from[0], n);
            int toNum = findName(to[0], n);
            matrix[fromNum][toNum] = weight;
            matrix[toNum][fromNum] = weight;
        }
        char *ans = (char *)calloc(sizeof(char), n);
        int *ansDis = (int *)calloc(sizeof(int), n);
        int ansRunner = 0;
        dist = (int *)calloc(sizeof(int), n);
        for (int i = 0; i < n; ++i) {
            if (status[i] == DIS) continue;
            connectedComponent = (int *)calloc(sizeof(int), n);
            runner = 0;
            findComponent(matrix, n, i);
            /*printf("connected component");
            for (int i = 0; i < runner; ++i) {
                printf(" %d",connectedComponent[i]);
            }
            printf("\n");*/
            for (int j = 0; j < runner; ++j) {
                statusTmp = (int *)calloc(sizeof(int), n);
                int sumDist = 0;
                for (int k = 0; k < n; ++k) {
                    dist[k] = INT_MAX;
                }
                dist[connectedComponent[j]] = 0;
                findShortestPath(matrix, n, connectedComponent[j]);
                //printf("dist =");
                for (int s = 0; s < n; ++s) {
                    if (dist[s] != INT_MAX && sumDist < dist[s]) {
                        sumDist = dist[s];
                    }
                    //printf(" %d",dist[s]);
                }
                //printf("\n");
                //printf("sumDist = %d at node %d\n",sumDist, connectedComponent[j]);
                free(statusTmp);
                if (ansDis[ansRunner] == 0) {
                    ansDis[ansRunner] = sumDist;
                    ans[ansRunner] = name[connectedComponent[j]];
                }
                else {
                    if (ansDis[ansRunner] > sumDist) {
                        ansDis[ansRunner] = sumDist;
                        ans[ansRunner] = name[connectedComponent[j]];
                    }
                }
                //printf("ans = %d\n",ansDis[ansRunner]);
            }
            ++ansRunner;
            free(connectedComponent);
        }
        printf("%d\n",ansRunner);
        for (int i = 0; i < ansRunner; ++i) {
            printf("%c ",ans[i]);
            //printf("dist = %d\n",ansDis[i]);
        }
    //}
}