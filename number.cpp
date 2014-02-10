#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    sort(array, array+n);
    if (array[0] == 0) {
        for (int i = 0; i < n; ++i) {
            if (array[i] != 0) {
                swap(array[i], array[0]);
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d",array[i]);
    }
}