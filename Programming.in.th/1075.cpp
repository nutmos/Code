#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct data {
    int canDestroyData;
    int eatElectric;
};

int compare (const void *a, const void *b) {
    return (*(data*)a).eatElectric - (*(data*)b).eatElectric;
}

int main() {
    int n;
    scanf("%d",&n);
    data worm[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&worm[i].canDestroyData, &worm[i].eatElectric);
    }
    qsort(worm, n, sizeof(data), compare);
    /*for (int i = 0; i < n; ++i) {
        printf("%d %d\n",worm[i].canDestroyData, worm[i].eatElectric);
    }*/
    long long destroyData = 0, energy = 0;
    long long answerData, answerElectric;
    double ratio = 0;
    for (int i = 0; i < n; ++i) {
        destroyData += worm[i].canDestroyData;
        energy = worm[i].eatElectric;
        double ratioTmp = (double)destroyData/(double)energy;
        if (ratioTmp > ratio) {
            answerData = destroyData;
            answerElectric = energy;
            ratio = ratioTmp;
        }
        else if (ratioTmp == ratio) {
            if (answerElectric > energy) {
                answerElectric = energy;
                answerData = destroyData;
            }
        }
    }
    printf("%lld %lld",answerData, answerElectric);
}