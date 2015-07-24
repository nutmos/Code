#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int tmp;
    unsigned long long max = 0;
    unsigned long long **ans = new unsigned long long*[n+1];
    bool ***status = new bool**[n+1];
    int maxIndex;
    if (n == 1) {
        scanf("%d",&tmp);
        printf("%lf",(double)tmp/100);
        return 0;
    }
    for (int i = 0; i <= n; ++i) {
        ans[i] = new unsigned long long[n+1];
        status[i] = new bool*[n+1];
        if (i == 0) {
            for (int j = 0; j <= n; ++j) {
                ans[i][j] = 1;
                status[i][j] = (bool *)calloc(sizeof(bool), n+1);
                //status[i][j][j] = true;
            }
        }
        else {
            for (int j = 0; j <= n; ++j) {
                if (j == 0) {
                    ans[i][j] = 1;
                    status[i][j] = (bool *)calloc(sizeof(bool), n+1);
                }
                else {
                    scanf("%d",&tmp);
                    max = 0;
                    status[i][j] = (bool *)calloc(sizeof(bool), n+1);
                    for (int k = 1; k <= n; ++k) {
                        //printf("k = %d, ans[%d][%d] = %d, status[%d][%d][%d] = %s\n",k,i-1,k,ans[i-1][k],i-1,k,j,(status[i-1][k][j] == false)?"false":"true");
                        if (ans[i-1][k] > max && status[i-1][k][j] == false) {
                            max = ans[i-1][k];
                            //printf("max changed to %d\n",max);
                            maxIndex = k;
                        }
                    }
                    for (int k = 0; k <= n; ++k) {
                        status[i][j][k] = status[i-1][maxIndex][k];
                    }
                    status[i][j][j] = true;
                    //printf("max = %d ",max);
                    ans[i][j] = max * tmp;
                    //printf("%d\n",ans[i][j]);
                }
            }
        }
        if (i >= 2) {
            delete [] ans[i-2];
            for (int j = 0; j <= n; ++j) {
                delete [] status[i-2][j];
            }
            delete [] status[i-2];
        }
        //printf("\n");
    }
    max = 0;
    for (int i = 1; i <= n; ++i) {
        if (max < ans[n][i]) {
            max = ans[n][i];
        }
    }
    printf("%Lf",(long double)max/pow(10, n<<1)*100);
}