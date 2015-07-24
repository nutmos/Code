#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int *array = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    int *ans = new int[n];
    ans[0] = 0;
    int profit;
    for (int i = 1; i < n; ++i) {
        profit = array[i] - array[i-1];
        if (profit > 0) {
            ans[i] = ans[i-1]+profit;
        }
        else {
            ans[i] = ans[i-1];
        }
        //printf("%d ",ans[i]);
    }
    int m,from,to;
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&from,&to);
        printf("%d\n",ans[to-1]-ans[from-1]);
    }
}