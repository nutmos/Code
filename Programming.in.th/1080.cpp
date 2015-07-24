#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int compare(const void *a, const void *b) {
    return (*(int*)a)-(*(int*)b);
}

int main() {
    int n;
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    if (n < 3) {
    	printf("%d",n);
    	return 0;
    }
    qsort(array, n, sizeof(int), compare);
    if (n == 3) {
    	if (array[0] + array[1] > array[2]) {
    		printf("3");
    		return 0;
    	}
    	else {
    		printf("0");
    		return 0;
    	}
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%d\n",array[i]);
    }*/
    int maxSet = 0;
    int sum;
    int set;
    for (int i = 0; i < n-2; ++i) {
        sum = array[i] + array[i+1];
        for (int j = n-1; j >= i+2; --j) {
            if (array[j] < sum) {
                set = j-i+1;
                if (set > maxSet) {
                    maxSet = set;
                }
                break;
            }
        }
        if (n-maxSet+1 < i) {
            break;
        }
        //printf("i = %d\n",i);
    }
    printf("%d",maxSet);
}