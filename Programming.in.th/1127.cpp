#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    int money;
    scanf("%d",&money);
    int array[10];
    scanf("%d",&array[1]);
    int min = array[1];
    for (int i = 2; i < 10; ++i) {
        scanf("%d",&array[i]);
        if (array[i] < min) {
            min = array[i];
        }
    }
    int maxDigit = money/min;
    int remain = money;
    int digit[maxDigit];
    for (int i = 0; i < maxDigit; ++i) {
        for (int j = 9; j >= 1; --j) {
            if (remain - array[j] >= 0) {
                if ((remain-array[j])/min >= maxDigit-i-1) {
                    remain -= array[j];
                    //printf("remain = %d\n",remain);
                    digit[i] = j;
                    //printf("j = %d\n",j);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < maxDigit; ++i) {
        printf("%d",digit[i]);
    }
}