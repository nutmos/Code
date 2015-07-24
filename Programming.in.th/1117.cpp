#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

void reheap_up(long long int array[], int index) {
    if (index != 0) {
        int parentIndex = ((index+1)>>1)-1;
        if (array[parentIndex] > array[index]) {
            long long int tmp = array[parentIndex];
            array[parentIndex] = array[index];
            array[index] = tmp;
            reheap_up(array, parentIndex);
        }
    }
}

void reheap_down(long long int array[], int index, int end) {
    int leaf1 = (index<<1)+1, leaf2 = (index<<1)+2;
    if (leaf2 > end) {
        if (leaf1 <= end) {
            if (array[leaf1] < array[index]) {
                long long int tmp = array[leaf1];
                array[leaf1] = array[index];
                array[index] = tmp;
                reheap_down(array, leaf1, end);
            }
        }
    }
    else {
        if (array[leaf1] < array[leaf2]) {
            if (array[leaf1] < array[index]) {
                long long int tmp = array[leaf1];
                array[leaf1] = array[index];
                array[index] = tmp;
                reheap_down(array, leaf1, end);
            }
        }
        else {
            if (array[leaf2] < array[index]) {
                long long int tmp = array[leaf2];
                array[leaf2] = array[index];
                array[index] = tmp;
                reheap_down(array, leaf2, end);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    long long int array[n];
    for (int i = 0; i < n; ++i) {
        int energy, exp;
        scanf("%d %d",&energy, &exp);
        array[i] = exp-(energy<<1);
        reheap_up(array, i);
    }
    for (int i = n-1; i > 0; --i) {
        long long int tmp = array[i];
        array[i] = array[0];
        array[0] = tmp;
        reheap_down(array, 0, i-1);
    }
    /*for (int i = 0; i < n; ++i) {
     printf("%d\n",array[i]);
     }*/
    long long int ans = array[0] - ((long long)n-1)*((long long)n-1);
    long long int sum = array[0];
    long long int sumTmp;
    for (int i = 1; i < n; ++i) {
        sumTmp = sum;
        sumTmp += array[i] - ((long long)n-1-i)*((long long)n-1-i);
        //printf("sum = %d, sumTmp = %d\n",sum,sumTmp);
        if (sumTmp > ans) {
            ans = sumTmp;
            sum += array[i];
        }
        else {
            break;
        }
    }
    printf("%lld",ans);
}