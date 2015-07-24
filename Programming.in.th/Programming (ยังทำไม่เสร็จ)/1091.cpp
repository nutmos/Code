#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define UNDIS false
#define DIS true

using namespace std;

class graph {
    struct node {
        int data;
        node *next;
    }*adajency;
    bool *status;
    int nVertex;
    int maxWay;
    int *dist;
public:
    void init(int n) {
        nVertex = n;
        adajency = new node[n];
        status = new bool[n];
        dist = new int[n];
        maxWay = 0;
        for (int i = 0; i < n; ++i) {
            adajency[i].next = &adajency[i];
        }
    }
    void addEdge(int from, int to) {
        node *n_node = new node;
        n_node->next = adajency[from].next;
        n_node->data = to;
        adajency[from].next = n_node;
    }
    int compare(int num1, int num2) {
        return (num1 > num2)?num1:num2;
    }
    void dijkstra(int vertex) {
        status[vertex] = DIS;
        if (maxWay < dist[vertex]) {
            maxWay = dist[vertex];
        }
        node *ptr = adajency[vertex].next;
        while (ptr != &adajency[vertex]) {
            dist[ptr->data] = compare(dist[ptr->data], dist[vertex]+1);
            ptr = ptr->next;
        }
        ptr = adajency[vertex].next;
        while (ptr != &adajency[vertex]) {
            if (status[ptr->data] == UNDIS && ptr->data > vertex) {
                dijkstra(ptr->data);
            }
            ptr = ptr->next;
        }
    }
    int callMaxWay() {
        return maxWay;
    }
    void clearStatusAndDist() {
        delete [] status;
        status = new bool[nVertex];
        delete [] dist;
        dist = new int[nVertex];
    }
};

int main() {
    int n;
    scanf("%d",&n);
    graph g;
    g.init(n);
    for (int i = 0; i < n-1; ++i) {
        int from,to;
        scanf("%d %d",&from,&to);
        g.addEdge(--from, --to);
    }
    for (int i = 0; i < n; ++i) {
        g.dijkstra(i);
        g.clearStatusAndDist();
    }
    printf("%d",g.callMaxWay()+1);
}