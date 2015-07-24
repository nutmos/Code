#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int factory[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&factory[i]);
        sum += factory[i];
    }
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int ans1, ans2;
    int max = 0;
    int min = INT_MAX;
    int diff = INT_MAX;
    sum1 = 0;
    for (int j = 1; j < n-1; ++j) {
        sum1 += factory[j-1];
        sum2 = 0;
        for (int k = j+1; k < n; ++k) {
            sum2 += factory[k-1];
            max = 0;
            min = INT_MAX;
            sum3 = sum-sum1-sum2;
            //printf("sum1 = %d sum2 = %d sum3 = %d\n",sum1, sum2, sum3);
            max = (sum1>max)?sum1:max;
            max = (sum2>max)?sum2:max;
            max = (sum3>max)?sum3:max;
            min = (sum1<min)?sum1:min;
            min = (sum2<min)?sum2:min;
            min = (sum3<min)?sum3:min;
            if (diff > max-min) {
                //printf("diff = %d\n",diff);
                diff = max-min;
                ans1 = j+1;
                ans2 = k+1;
                if (diff == 0) {break;}
            }
        }
        if (diff == 0) {break;}
    }
    //printf("diff = %d\n",diff);
    printf("%d %d",ans1, ans2);
}