#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

int minEnergy = INT_MAX;
int moveBox = 0;
int n;

void moveBoxBT(int boxStack[], int move, int sumEnergy, int robotAt) {
    if (move == moveBox) {
        minEnergy = min(minEnergy, sumEnergy);
    }
    if (sumEnergy > minEnergy) {
        //printf("test\n");
        return;
    }
    //printf("sumEnergy = %d\n",sumEnergy);
    for (int i = 0; i < n; ++i) {
        //printf("i = %d\n",i);
        if (boxStack[i] > 0) {
            //printf("i = %d\n",i);
            --boxStack[i];
            for (int j = 0; j < n; ++j) {
                if (boxStack[j] < 0) {
                    //printf("boxStack[j] = %d\n",boxStack[j]);
                    ++boxStack[j];
                    moveBoxBT(boxStack, move+1, sumEnergy+abs(robotAt-i)+abs(i-j), j);
                    --boxStack[j];
                }
            }
            ++boxStack[i];
        }
    }
}

int main() {
    scanf("%d",&n);
    int sum = 0;
    int boxStack[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&boxStack[i]);
        sum += boxStack[i];
    }
    if (sum % n != 0) {
        printf("0");
        return 0;
    }
    int avg = sum/n;
    for (int i = 0; i < n; ++i) {
        boxStack[i] -= avg;
        if (boxStack[i] > 0) {
            moveBox += boxStack[i];
        }
        //printf("%d ",boxStack[i]);
    }
    moveBoxBT(boxStack, 0, 0, 0);
    printf("%d %d",moveBox,minEnergy);
}