#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int *array1 = new int[n], *array2 = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&array1[i],&array2[i]);
    }
    long long sum = 0;
    sort(array1, array1+n);
    sort(array2, array2+n);
    int multiply = -n+1;
    for (int i = 0; i < n; ++i) {
        sum += ((long long)array1[i] * multiply) + ((long long)array2[i] * multiply);
        multiply += 2;
    }
    printf("%.lld",sum);
}