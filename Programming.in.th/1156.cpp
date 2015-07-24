#include <iostream>
#include <cstdio>
#include <cstdlib>
#define WIN 1
#define LOOSE 2

using namespace std;

int n;
int begin;
int *set;

void permutation(int setIndex, int countWin, int countLoose, int setSize) {
    if (countWin == n || countLoose == n || setIndex == setSize) {
        for (int i = begin; i < setIndex; ++i) {
            printf("%c",(set[i] == WIN)?'W':'L');
            if (i != setIndex-1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }
    else {
        set[setIndex] = WIN;
        permutation(setIndex+1, countWin+1, countLoose,setSize);
        set[setIndex] = LOOSE;
        permutation(setIndex+1, countWin, countLoose+1,setSize);
    }
}

int main() {
    int winSet,looseSet;
    scanf("%d %d %d",&n,&winSet,&looseSet);
    set = (int *)calloc(sizeof(int), (n << 1)+1);
    int setIndex = 0;
    for (int i = 0; i < looseSet; ++i) {
        set[setIndex++] = LOOSE;
    }
    for (int i = 0; i < winSet; ++i) {
        set[setIndex++] = WIN;
    }
    begin = setIndex;
    //printf("setIndex = %d\n",setIndex);
    permutation(setIndex, winSet, looseSet,(n<<1)+1);
}