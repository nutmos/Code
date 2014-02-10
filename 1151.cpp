#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int tree[200000];

int main() {
    int n;
    scanf("%d",&n);
    scanf("%d",&tree[0]);
    int ans[2];
    ans[0] = 1;
    int cur = 1;
    int before = 0;
    int max = 1;
    int hightestTreeCanFind = ans[0];
    for (int i = 1; i < n; ++i) {
        scanf("%d",&tree[i]);
        if (tree[i] > tree[i-1]) {
            if (tree[i] > hightestTreeCanFind) {
                ans[cur] = max+1;
            }
            else {
                ans[cur] = ans[before]+1;
            }
        }
        else if (tree[i] == tree[i-1]) {
            ans[cur] = ans[before];
        }
        else {
            ans[cur] = 1;
        }
        if (max < ans[cur]) {
            max = ans[cur];
        }
        if (tree[i] > hightestTreeCanFind) {
            hightestTreeCanFind = tree[i];
        }
        before = cur;
        cur = 1-cur;
    }
    printf("%d",max);
}