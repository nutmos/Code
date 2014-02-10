#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int point = 0;
    int x,y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&x,&y);
        int multiply = x*x + y*y;
        if (multiply <= 4) {
            point += 5;
        }
        else if (multiply <= 16) {
            point += 4;
        }
        else if (multiply <= 36) {
            point += 3;
        }
        else if (multiply <= 64) {
            point += 2;
        }
        else if (multiply <= 100) {
            point += 1;
        }
    }
    printf("%d",point);
}