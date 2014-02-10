#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#define YES true
#define NO false

using namespace std;
int *food, n;

bool isAllRot() {
    for (int i = 0; i < n; ++i) {
        if (food[i] == 0) {
            return YES;
        }
    }
    return NO;
}

void calculateMin(int &min, int &minIndex) {
    for (int i = 0; i < n; ++i) {
        if (food[i] < min) {
            min = food[i];
            minIndex = i;
        }
    }
}

int main() {
    scanf("%d",&n);
    food = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&food[i]);
    }
    int minIndex = 0;
    int min = INT_MAX;
    int countDay = 0;
    while (!isAllRot()) {
        calculateMin(min, minIndex);
        for (int i = 0; i < n; ++i) {
            if (i != minIndex) {
                --food[i];
            }
        }
        ++countDay;
    }
    printf("%d",countDay);
}