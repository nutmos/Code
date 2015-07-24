#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int *land = (int *)calloc(sizeof(int), 1000);
    int from,to,tall;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d",&from,&tall,&to);
        for (int j = from<<1; j <= to<<1; ++j) {
            if (tall > land[j]) {
                land[j] = tall;
            }
        }
    }
    int firstTime = 0;
    for (int i = 1; i <= 1000; ++i) {
        if (land[i] > land[i-1]) {
            if (firstTime == 0) {
                //printf("1 ");
                printf("%d %d",i>>1,land[i]);
                //printf("\n");
                firstTime = 1;
            }
            else printf(" %d %d",i>>1,land[i]);
        }
        else if (land[i] < land[i-1]) {
            if (firstTime == 0) {
                printf("%d %d",i>>1,land[i]);
                firstTime = 1;
            }
            else printf(" %d %d",i>>1,land[i]);
        }
    }
}