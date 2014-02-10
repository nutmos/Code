#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n,q;
    scanf("%d %d",&n,&q);
    int *array = (int *)calloc(sizeof(int), n);
    int *maxVal = (int *)calloc(sizeof(int), n);
    char ch[2];
    int n1,n2,maxNum;
    for (int i = 0; i < q; ++i) {
        scanf("%s %d %d",ch,&n1,&n2);
        if (ch[0] == 'U') {
            array[--n1] = n2;
            /*if (n1 == 0) {
                maxVal[0] = n2;
            }
            else {
                for (int i = n1; i < n; ++i) {
                    if (maxVal[i-1] < array[i]) {
                        maxVal[i] = array[i];
                        break;
                    }
                    else {
                        maxVal[i] = maxVal[i-1];
                    }
                }
            }*/
        }
        else {
            --n1;
            --n2;
            maxNum = array[n1];
            //if (maxVal[n2] == maxVal[n1-1]) {
                for (int i = n1+1; i <= n2; ++i) {
                    maxNum = max(maxNum, array[i]);
                }
            //}
            //else {
                //maxNum = maxVal[n2];
            //}
            printf("%d\n",maxNum);
        }
    }
}