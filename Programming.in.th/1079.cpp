#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    if (k == 1) {
        printf("1\n");
        return 0;
    }
    int *array = new int[n];
    int sum = 2;
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < n; ++i) {
        array[i] = sum;
        if (array[i] > 2008) {
            array[i] %= 2009;
        }
        sum += array[i];
        //printf("i = %d %d %d ",i,array[i-k],ans[i]);
        if (i >= k) {
            sum -= array[i-k];
        }
        sum += 2009;
        sum %= 2009;
        //printf("%d\n",ans[i]);
    }
    printf("%d\n",sum % 2009);
}