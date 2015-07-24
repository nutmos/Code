#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

struct equipment {
    int price;
    int *canUse;
};

int minPrice = INT_MAX;

int n,k;

void calculateMin(equipment array[], bool canDo[], int index, int price) {
    if (index < n && price <= minPrice) {
        calculateMin(array, canDo, index+1, price);
        bool *n_canDo = new bool[k];;
        for (int i = 0; i < k; ++i) {
            if (array[index].canUse[i] || canDo[i]) n_canDo[i] = true;
            else n_canDo[i] = false;
        }
        calculateMin(array, n_canDo, index+1, price+array[index].price);
        delete [] n_canDo;
    }
    else {
        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (canDo[i] == true) {
                ++count;
            }
            else break;
        }
        if (count == k) {
            if (minPrice > price) {
                minPrice = price;
            }
        }
        //printf("count = %d price = %d\n", count,price);
    }
}

int main() {
    scanf("%d %d",&n,&k);
    equipment array[n];
    for (int i = 0; i < n; ++i) {
        array[i].canUse = new int[k];
        scanf("%d",&array[i].price);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&array[i].canUse[j]);
        }
    }
    bool *canDo = (bool *)calloc(sizeof(bool), k);
    calculateMin(array, canDo, 0, 0);
    printf("%d",minPrice);
}