#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long long set[n];
    long long summary[n+1];
    summary[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&set[i]);
        summary[i+1] = set[i] + summary[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (set[i] * i) - summary[i];
        if (sum >= 49999) {
            sum %= 49999;
        }
    }
    for (int i = 2; i <= n-2; ++i) {
        sum *= i;
        if (sum >= 49999) sum %= 49999;
    }
    printf("%lld",sum);
}