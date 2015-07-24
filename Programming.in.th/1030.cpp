#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct rice {
    int kilo;
    double pricePerOneKilo;
};

int cmp(const void *a, const void *b) {
    if (((rice*)a)->pricePerOneKilo > ((rice*)b)->pricePerOneKilo) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    rice *array = new rice[n];
    int price;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&price,&array[i].kilo);
        array[i].pricePerOneKilo = (double)price/array[i].kilo;
    }
    qsort(array, n, sizeof(rice), cmp);
    /*for (int i = 0; i < n; ++i) {
        printf("%lf\n",array[i].pricePerOneKilo);
    }*/
    int arrayIndex = 0;
    int m;
    int kilo;
    double sum = 0;
    scanf("%d",&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&kilo);
        sum = 0;
        while (kilo > 0) {
            if (array[arrayIndex].kilo > kilo) {
                sum += array[arrayIndex].pricePerOneKilo * (double)kilo;
                array[arrayIndex].kilo -= kilo;
                kilo = 0;
            }
            else {
                sum += array[arrayIndex].pricePerOneKilo * (double)array[arrayIndex].kilo;
                kilo -= array[arrayIndex].kilo;
                //array[arrayIndex].kilo = 0;
                ++arrayIndex;
            }
        }
        printf("%.3lf\n",sum);
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%lf %d\n",array[i].pricePerOneKilo,array[i].kilo);
    }*/
}