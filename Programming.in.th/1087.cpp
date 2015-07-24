#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int **array = new int*[n];
    int **ans = new int*[n];
    for (int i = 0; i < n; ++i) {
        array[i] = new int[m];
        ans[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            scanf("%d",&array[i][j]);
            ans[i][j] = array[i][j];
        }
    }
    int sum;
    bool mIsOdd = m%2;
    bool nIsOdd = n%2;
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = 0; j < m; ++j) {
            if (j % 2 == 0) {
                ans[i][j] += sum;
                sum += array[i][j];
            }
            else {
                ans[i][j] -= sum;
                sum -= array[i][j];
            }
            if (j >= q) {
                if ((j-q) % 2 == 0) {
                    sum -= array[i][j-q];
                }
                else {
                    sum += array[i][j-q];
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    for (int i = 0; i < n; ++i) {
        sum = 0;
        for (int j = m-1; j >= 0; --j) {
            if (mIsOdd) {
                if (j % 2 == 0) {
                    ans[i][j] += sum;
                    sum += array[i][j];
                }
                else {
                    ans[i][j] -= sum;
                    sum -= array[i][j];
                }
                if (j+q < m) {
                    if ((j+q) % 2 == 0) {
                        sum -= array[i][j+q];
                    }
                    else {
                        sum += array[i][j+q];
                    }
                }
            }
            else {
                if (j % 2 == 0) {
                    ans[i][j] -= sum;
                    sum -= array[i][j];
                }
                else {
                    ans[i][j] += sum;
                    sum += array[i][j];
                }
                if (j+q < m) {
                    if ((j+q) % 2 == 0) {
                        sum += array[i][j+q];
                    }
                    else {
                        sum -= array[i][j+q];
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    for (int i = m-1; i >= 0; --i) {
        sum = 0;
        for (int j = 0; j < n; ++j) {
            if (j % 2 == 0) {
                ans[j][i] += sum;
                sum += array[j][i];
            }
            else {
                ans[j][i] -= sum;
                sum -= array[j][i];
            }
            if (j >= q) {
                if ((j-q) % 2 == 0) {
                    sum -= array[j-q][i];
                }
                else {
                    sum += array[j-q][i];
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    for (int i = m-1; i >= 0; --i) {
        sum = 0;
        for (int j = n-1; j >= 0; --j) {
            if (nIsOdd) {
                if (j % 2 == 0) {
                    ans[j][i] += sum;
                    sum += array[j][i];
                }
                else {
                    ans[j][i] -= sum;
                    sum -= array[j][i];
                }
                if (j+q < n) {
                    if ((j+q) % 2 == 0) {
                        sum -= array[j+q][i];
                    }
                    else {
                        sum += array[j+q][i];
                    }
                }
            }
            else {
                if (j % 2 == 0) {
                    ans[j][i] -= sum;
                    sum -= array[j][i];
                }
                else {
                    ans[j][i] += sum;
                    sum += array[j][i];
                }
                if (j+q < n) {
                    if ((j+q) % 2 == 0) {
                        sum += array[j+q][i];
                    }
                    else {
                        sum -= array[j+q][i];
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");*/
    int max = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] > max) {
                max = ans[i][j];
            }
        }
    }
    printf("%d",max);
}