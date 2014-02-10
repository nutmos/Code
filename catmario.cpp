#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n,m;
    int sum = 0;
    scanf("%d %d",&n,&m);
    int *level = (int *)calloc(sizeof(int), n);
    int x,y;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&x,&y);
        if (level[x-1] == 0) {
            sum += y;
            level[x-1] = y;
        }
        else if (level[x-1] > y) {
            sum = sum - level[x-1] + y;
            level[x-1] = y;
        }
    }
    printf("%d\n",sum);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n",i+1,level[i]);
    }
}