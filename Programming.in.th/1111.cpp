#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#define UNDIS false
#define DIS true

using namespace std;

class graph {
    struct list {
        list *prev;
        int data;
        int weight;
        list *next;
    } *adajency;
    int nVertex;
    int *dist;
    bool *status;
    
public:
    void init(int n) {
        adajency = new list[n];
        dist = new int[n];
        status = new bool[n];
        for (int i = 0; i < n; ++i) {
            adajency[i].next = &adajency[i];
            adajency[i].prev = &adajency[i];
            dist[i] = INT_MAX;
            status[i] = UNDIS;
        }
        dist[0] = 0;
        nVertex = n;
    }
    void addEdge(int from, int to, int weight) {
        list *n_list = new list;
        n_list->data = to;
        n_list->weight = weight;
        n_list->next = adajency[from].next;
        n_list->prev = &adajency[from];
        adajency[from].next->prev = n_list;
        adajency[from].next = n_list;
    }
    void dfs(int node) {
        status[node] = DIS;
        list *ptr = adajency[node].next;
        while (ptr != &adajency[node]) {
            if (dist[ptr->data] > dist[node]+ptr->weight) {
                dist[ptr->data] = dist[node]+ptr->weight;
            }
            ptr = ptr->next;
        }
        ptr = adajency[node].next;
        while (ptr != &adajency[node]) {
            if (status[ptr->data] == UNDIS) dfs(ptr->data);
            ptr = ptr->next;
        }
    }
    void printDist() {
        for (int i = 0; i < nVertex; ++i) {
            printf("dist[%d] = %d\n",i,dist[i]);
        }
    }
    int maxDist() {
        int Max = 0;
        for (int i = 1; i < nVertex; ++i) {
            if (dist[i] > Max) Max = dist[i];
        }
        return Max;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    graph g;
    g.init(n);
    for (int i = 0; i < n-1; ++i) {
        int from, to, weight;
        scanf("%d %d %d",&from,&to,&weight);
        --from; --to;
        g.addEdge(from, to, weight);
        g.addEdge(to, from, weight);
    }
    g.dfs(0);
    //g.printDist();
    printf("%d",g.maxDist());
}