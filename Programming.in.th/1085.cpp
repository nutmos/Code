#include <iostream>
#include <cstdlib>
#include <cstdio>
#define UNDIS 0
#define DIS 1

using namespace std;

int *status;

struct graph {
    graph *prev;
    int data;
    graph *next;
};

void delEdge (graph g[], int node) {
    graph *ptr = g[node].next;
    while (ptr != &g[node]) {
        if (ptr->data == node+1) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            return;
        }
        ptr = ptr->next;
    }
}

void addEdge (graph g[], int from, int to) {
    //printf("to = %d\n",to);
    graph *n = new graph;
    n->data = to;
    n->prev = &g[from];
    n->next = g[from].next;
    g[from].next->prev = n;
    g[from].next = n;
}
void dfs(graph g[], int node, int n) {
    //printf("node = %d\n",node);
    if (status[node] == DIS) {
        return;
    }
    status[node] = DIS;
    /*for (int i = 0; i < n; ++i) {
     if (matrix[node][i] == 1 && status[i] == UNDIS) {
     dfs(matrix, i, n);
     }
     }*/
    graph *ptr = g[node].next;
    while (ptr != &g[node]) {
        dfs(g, ptr->data, n);
        ptr = ptr->next;
    }
}

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    graph *g = new graph[n];
    status = (int *)calloc(sizeof(int), n);
    for (int i = 0; i < n; ++i) {
        g[i].data = i;
        g[i].next = &g[i];
        g[i].prev = &g[i];
        if (i != n-1) {
            addEdge(g, i, i+1);
        }
    }
    int from, to;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&from,&to);
        addEdge(g, from-1, to-1);
    }
    int rock;
    for (int i = 0; i < k; ++i) {
        scanf("%d",&rock);
        //addEdge(g, rock-1, rock);
        delEdge(g, rock-1);
    }
    /*for (int i = 0; i < n; ++i) {
        graph *ptr = g[i].next;
        //printf("%d -> ",i);
        while (ptr != &g[i]) {
            printf("%d ",ptr[i].data);
            ptr = ptr->next;
        }
        //printf("status = %d\n",status[i]);
    }*/
    dfs(g, 0,n);
    if (status[n-1] == DIS) {
        printf("1");
    }
    else {
        printf("0");
        for (int i = n-2; i >= 0; --i) {
            if (status[i] == DIS) {
                printf(" %d",i+1);
                return 0;
            }
        }
    }
}