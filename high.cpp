#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,p,r;

int method;

void permute(bool isUse[], int array[], int index) {
    if (index == n) {
        int max = -1;
        int leftSee = 0;
        for (int i = 0; i < n; ++i) {
            if (array[i] > max) {
                ++leftSee;
                max = array[i];
            }
        }
        if (leftSee != p) {
            return;
        }
        max = -1;
        int rightSee = 0;
        for (int i = n-1; i >= 0; --i) {
            if (array[i] > max) {
                ++rightSee;
                max = array[i];
            }
        }
        if (leftSee == p && rightSee == r) {
            /*for (int i = 0; i < n; ++i) {
                printf("%d ",array[i]);
            }
            printf("\n");*/
            ++method;
        }
        else return;
    }
    for (int i = 0; i < n; ++i) {
        if (isUse[i] == false) {
            isUse[i] = true;
            array[index] = i;
            permute(isUse, array, index+1);
            isUse[i] = false;
        }
    }
}

int main() {
    scanf("%d %d %d",&n,&p,&r);
    method = 0;
    bool *isUse = (bool *)calloc(sizeof(bool), n);
    int array[n];
    permute(isUse, array, 0);
    printf("%d",method);
}