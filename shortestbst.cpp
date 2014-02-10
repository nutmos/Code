#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int a,b;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&a,&b);
        count = 0;
        while (a != 1 || b != 1) {
            ++count;
            (a > b)?a -= b:b -= a;
        }
        printf("%d\n",count);
    }
}