#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

struct way {
    int from;
    int to;
    int dist;
};

void swapWay(way *w1, way *w2) {
    way tmp = *w1;
    *w1 = *w2;
    *w2 = tmp;
}

void reheap_up(way array[], int index) {
    if (index == 0) return;
    int parent = (index-1)>>1;
    if (array[index].dist > array[parent].dist) {
        swapWay(&array[index], &array[parent]);
        reheap_up(array, parent);
    }
}

void reheap_down(way array[], int index, int end) {
    int leaf1 = (index<<1)+1, leaf2 = (index<<1)+2;
    if (leaf2 <= end) {
        if (array[leaf2].dist > array[leaf1].dist) {
            if (array[leaf2].dist > array[index].dist) {
                swapWay(&array[leaf2], &array[index]);
                reheap_down(array, leaf2, end);
            }
        }
        else {
            if (array[leaf1].dist > array[index].dist) {
                swapWay(&array[leaf1], &array[index]);
                reheap_down(array, leaf1, end);
            }
        }
    }
    else if (leaf2 > end && leaf1 <= end) {
        if (array[leaf1].dist > array[index].dist) {
            swapWay(&array[leaf1], &array[index]);
            reheap_down(array, leaf1, end);
        }
    }
    else return;
}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    way array[m];
    int *inTree = (int *)calloc(sizeof(int), n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&array[i].from,&array[i].to,&array[i].dist);
        array[i].from -= 1;
        array[i].to -= 1;
        reheap_up(array, i);
    }
    for (int i = m-1; i > 0; --i) {
        swapWay(&array[i], &array[0]);
        reheap_down(array, 0, i-1);
    }
    /*for (int i = 0; i < m; ++i) {
        printf("dist = %d\n",array[i].dist);
    }*/
    int numTree = 1;
    int count = 0;
    for (int i = 0; i < m; ++i) {
        if (inTree[array[i].from] == 0 && inTree[array[i].to] == 0) {
            inTree[array[i].from] = numTree;
            inTree[array[i].to] = numTree;
            ++numTree;
            printf("%d %d\n",array[i].from+1, array[i].to+1);
            ++count;
            //printf("lastAns = %d %d %d\n",ans.back().from+1, ans.back().to+1,ans.back().dist);
        }
        else if (inTree[array[i].from] != 0 && inTree[array[i].to] == 0) {
            inTree[array[i].to] = inTree[array[i].from];
            printf("%d %d\n",array[i].from+1, array[i].to+1);
            ++count;
            //printf("lastAns = %d %d %d\n",ans.back().from+1, ans.back().to+1,ans.back().dist);
        }
        else if (inTree[array[i].to] != 0 && inTree[array[i].from] == 0) {
            inTree[array[i].from] = inTree[array[i].to];
            printf("%d %d\n",array[i].from+1, array[i].to+1);
            ++count;
            //printf("lastAns = %d %d %d\n",ans.back().from+1, ans.back().to+1,ans.back().dist);
        }
        else {
            if (inTree[array[i].to] > inTree[array[i].from]) {
                int tmp = inTree[array[i].to];
                for (int j = 0; j < n; ++j) {
                    if (inTree[j] == tmp) {
                        inTree[j] = inTree[array[i].from];
                    }
                }
                printf("%d %d\n",array[i].from+1, array[i].to+1);
                ++count;
                //printf("lastAns = %d %d %d\n",ans.back().from+1, ans.back().to+1,ans.back().dist);
            }
            else if (inTree[array[i].to] < inTree[array[i].from]) {
                int tmp = inTree[array[i].from];
                for (int j = 0; j < n; ++j) {
                    if (inTree[j] == tmp) {
                        inTree[j] = inTree[array[i].to];
                    }
                }
                printf("%d %d\n",array[i].from+1, array[i].to+1);
                ++count;
                //printf("lastAns = %d %d %d\n",ans.back().from+1, ans.back().to+1,ans.back().dist);
            }
        }
        if (count == n-1) break;
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%d\n",inTree[i]);
    }*/
}