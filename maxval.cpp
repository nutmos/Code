#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int area[n];
    scanf("%d",&area[0]);
    int sum = area[0];
    for (int i = 1; i < m; ++i) {
        scanf("%d",&area[i]);
        sum += area[i];
    }
    int max = sum;
    for (int i = m; i < n; ++i) {
        scanf("%d",&area[i]);
        sum += area[i] - area[i-m];
        if (sum > max) {
            max = sum;
        }
    }
    printf("%d",max);
}