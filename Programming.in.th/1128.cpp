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
        if (i > 0) {
            array[i] += array[i-1];
            if (array[i] > 2553) array[i] %= 2553;
        }
    }
    int sum = array[0];
    for (int i = 1; i < n; ++i) {
        array[i] += array[i-1];
        sum += array[i];
        if (sum > 2553) sum %= 2553;
    }
    printf("%d",sum);
}