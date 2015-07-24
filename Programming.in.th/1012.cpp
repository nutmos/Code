#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int a,b,c,d,e;
    int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        countA += a; countB += b; countC += c; countD += d; countE += e;
    }
    int cake = 0;
    cake += countA;
    int remainD = countB;
    int remainC;
    cake += countB;
    if (countC % 2 == 0) {
        cake += countC >> 1;
        remainC = 0;
    }
    else {
        cake += (countC >> 1) + 1;
        remainC = 1;
    }
    if (remainD >= countD) {
        remainD -= countD;
        countD = 0;
    }
    else {
        countD -= remainD;
        remainD = 0;
        if (countD % 4 == 0) {
            cake += countD >> 2;
        }
        else {
            cake += (countD >> 2) + 1;
        }
    }
    if (remainD >= 0 || remainC >= 0) {
        if ((remainD << 1) + (remainC << 2) < countE) {
            //printf("test\n");
            countE -= (remainD << 1) + (remainC << 2);
            if (countE % 8 == 0) {
                //printf("test1\n");
                cake += countE >> 3;
            }
            else {
                cake += (countE >> 3) + 1;
            }
        }
        //else do nothing
    }
    printf("%d",cake);
}