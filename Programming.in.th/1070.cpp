#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int max = 0;
    int min = INT_MAX;
    int minIndex = 0;
    int branch[n];
    //int min2 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&branch[i]);
        if (branch[i] > max) {
            max = branch[i];
        }
        if (branch[i] < min) {
            min = branch[i];
            minIndex = i;
        }
    }
    int min2 = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (min2 > branch[i] && i != minIndex) {
            min2 = branch[i];
        }
    }
    if (n == 1 || n == 2) {
        printf("no");
    }
    else if (min + min2 > max) {
        printf("no");
    }
    else {
        printf("yes");
    }
}