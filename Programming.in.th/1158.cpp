#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int **area = new int*[n];
    int **sum = new int*[n];
    int center;
    int maxPeople = 0;
    int tmp = 0;
    scanf("%d",&center);
    for (int i = 0; i < n; ++i) {
        area[i] = new int[m];
        sum[i] = new int[m];
        tmp = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d",&area[i][j]);
            if (i == 0) {
                sum[i][j] = area[i][j];
            }
            else if (i > 0 && i < center) {
                sum[i][j] = sum[i-1][j] + area[i][j];
            }
            else {
                sum[i][j] = sum[i-1][j] + area[i][j] - area[i-center][j];
            }
            if (j == center-1) {
                for (int k = 0; k < center; ++k) {
                    tmp += sum[i][k];
                }
                if (tmp > maxPeople) maxPeople = tmp;
            }
            else if (j >= center) {
                tmp += sum[i][j];
                tmp -= sum[i][j-center];
                if (tmp > maxPeople) {
                    maxPeople = tmp;
                }
            }
        }
        if (i >= center) {
            delete [] area[i-center];
        }
    }
    printf("%d",maxPeople);
}