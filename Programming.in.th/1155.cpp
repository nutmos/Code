//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
//First Compile with g++ 4.2.1 on OS X Mountain Lion 10.8.3
#include <iostream>
#include <cstdio>
#include <cstdlib>

struct fight {
    int time;
    int evenOrOdd;
};

int main() {
    int n;
    scanf("%d",&n);
    int tmp;
    int energyOdd = n, energyEven = n;
    fight statistic = {0,0};
    for (int i = 0; i < (n<<1); ++i) {
        //printf("i = %d\n", i);
        scanf(" %d ",&tmp);
        if (i != 0) {
            if (tmp % 2 == 0) {
                if (statistic.evenOrOdd == 0) {
                    ++statistic.time;
                    if (statistic.time >= 3) {
                        energyOdd -= 3;
                    }
                    else {
                        --energyOdd;
                    }
                }
                else {
                    statistic.time = 1;
                    statistic.evenOrOdd = 0;
                    --energyOdd;
                }
            }
            else {
                if (statistic.evenOrOdd == 1) {
                    ++statistic.time;
                    if (statistic.time >= 3) {
                        energyEven -= 3;
                    }
                    else {
                        --energyEven;
                    }
                }
                else {
                    statistic.time = 1;
                    statistic.evenOrOdd = 1;
                    --energyEven;
                }
            }
        }
        else {
            if (tmp % 2 == 0) {
                statistic.time = 1;
                statistic.evenOrOdd = 0;
                --energyOdd;
            }
            else {
                statistic.time = 1;
                statistic.evenOrOdd = 1;
                --energyEven;
            }
        }
        //printf("energyEven = %d energyOdd = %d\n", energyEven, energyOdd);
        if (energyEven <= 0) {
            printf("1\n%d\n",tmp);
            break;
        }
        else if (energyOdd <= 0) {
            printf("0\n%d\n",tmp);
            break;
        }
    }
}