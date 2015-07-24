#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n,m,q,n1,n2;
    scanf("%d %d %d",&n,&m,&q);
    bool *maxnet = (bool *)calloc(sizeof(bool), n);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&n1,&n2);
        --n1;
        for (int j = n1; j < n1+n2; ++j) {
            //printf("j = %d\n",j);
            maxnet[j] = !maxnet[j];
        }
        /*for (int j = 0; j < n; ++j) {
            printf("%d ",maxnet[j]);
        }*/
        //printf("\n");
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d",&n1);
        --n1;
        int top = n1, bottom = n1;
        for (int j = n1; j >= 0; --j) {
            if (maxnet[j] != maxnet[n1]) {
                break;
            }
            top = j;
        }
        for (int j = n1; j >= 0; ++j) {
            if (maxnet[j] != maxnet[n1]) {
                break;
            }
            bottom = j;
        }
        printf("%d\n",bottom-top+1);
    }
}