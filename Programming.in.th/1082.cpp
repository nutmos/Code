#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct way {
    int from;
    int to;
    int weight;
};

int *status;

int findHead(int node) {
    while (status[node] != 0) {
        node = status[node];
    }
    return node;
}

int compare (const void *a, const void *b) {
    return (*(way *)a).weight - (*(way *)b).weight;
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    way *array = new way[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&array[i].from,&array[i].to,&array[i].weight);
    }
    qsort(array, m, sizeof(way), compare);
    /*for (int i = 0; i < m; ++i) {
     printf("%d\n",array[i].weight);
     }*/
    status = (int *)calloc(n+1, sizeof(int));
    int countWay = 0;
    for (int i = 0; i < m; ++i) {
        int headFrom = findHead(array[i].from);
        int headTo = findHead(array[i].to);
        if (headFrom != headTo) {
            status[headTo] = headFrom;
            printf("%d %d\n",array[i].from,array[i].to);
            ++countWay;
        }
        if (countWay == n-1) {
            break;
        }
    }
}