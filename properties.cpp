#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n;

int method;

bool checkAntimonotonic(int array[], int n) {
    for (int i = 1; i < n-1; ++i) {
        if (array[i] > array[i-1] && array[i] > array[i+1]) {
            continue;
        }
        else if (array[i] < array[i-1] && array[i] < array[i+1]) {
            continue;
        }
        else return false;
    }
    return true;
}

bool checkCyclic(int array[], int n) {
    int ptr = array[0];
    int count = 0;
    while (ptr != 0) {
        ptr = array[ptr];
        ++count;
    }
    if (count == n-1) {
        return true;
    }
    else return false;
}

void permute(bool isUse[], int array[], int index) {
    if (index == n) {
        if (checkCyclic(array, n)) {
            if (checkAntimonotonic(array, n)) {
                ++method;
            }
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (isUse[i] == false) {
            if (i != index) {
                isUse[i] = true;
                array[index] = i;
                permute(isUse, array, index+1);
                isUse[i] = false;
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    method = 0;
    bool *isUse = (bool *)calloc(sizeof(bool), n);
    int array[n];
    permute(isUse, array, 0);
    printf("%d",method);
}