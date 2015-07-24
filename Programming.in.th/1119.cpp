#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct pakkarnmuang {
    int haveSorSor;
    int fromArrayI;
};

bool cmp(pakkarnmuang a, pakkarnmuang b) {
    return a.haveSorSor > b.haveSorSor;
}

int main() {
    int n,sum = 0;
    scanf("%d",&n);
    pakkarnmuang array[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i].haveSorSor);
        array[i].fromArrayI = i;
        sum += array[i].haveSorSor;
    }
    int ans[n];
    int minCanFormGovernment = (sum+2)>>1;
    vector<pakkarnmuang> vectorForSort (array, array+n);
    vector<int> vectorForSum (n);
    sort(vectorForSort.begin(), vectorForSort.end(), cmp);
    vectorForSum[0] = vectorForSort[0].haveSorSor;
    //printf("%d\n",vectorForSum[0]);
    for (int i = 1; i < n; ++i) {
        vectorForSum[i] = vectorForSum[i-1]+vectorForSort[i].haveSorSor;
        //printf("%d\n",vectorForSum[i]);
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        int sum, minToJoin = 0;
        while (1) {
            sum = vectorForSum[index];
            if (index < i) {
                sum += vectorForSort[i].haveSorSor;
            }
            if (sum >= minCanFormGovernment) {
                //printf("sum = %d\n",sum);
                minToJoin = index+1;
                if (index >= i) {
                    //printf("test\n");
                    --minToJoin;
                }
                --index;
                break;
            }
            ++index;
        }
        //printf("index = %d %d %d\n",index,vectorForSort[i].haveSorSor,minToJoin);
        ans[vectorForSort[i].fromArrayI] = minToJoin;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n",ans[i]);
    }
}