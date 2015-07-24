//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
//First Compile with Xcode 4.6.1
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int tail[n];
    for (int i = 0 ; i < n; i++) {
        scanf("%d",&tail[i]);
    }
    int a;
    scanf("%d",&a);
    int *array = (int *)calloc(sizeof(int), a+1);
    for (int i = 0; i < n; i++) {
        if (tail[i] <= a) {
            ++array[tail[i]];
        }
    }
    unsigned long long int sum = 0;
    for (int i = 0; i <= (a>>1); ++i) {
        if (i == a-i && array[i] > 1) {
            unsigned long long int combi = 1;
            for (int j = array[i]; j > array[i]-2; j--) {
                combi *= j;
            }
            sum += combi >> 1;
        }
        else sum += (unsigned long long int) array[i] * (unsigned long long int) array[a-i];
    }
    printf("%llu",sum);
}