#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int max (int n1, int n2) {
	//printf("n1 = %d, n2 = %d\n",n1,n2);
	return (n1 > n2)?n1:n2;
}

int main() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int sushiCut[m+2];
	sushiCut[0] = 0;
	sushiCut[m+1] = n;
	for (int i = 1; i <= m; ++i) {
		//printf("i = %d\n",i);
		scanf("%d",&sushiCut[i]);
	}
	int people[k+1];
	people[0] = 0;
	for (int i = 1; i <= k; ++i) {
		//printf("i = %d\n", i);
		scanf("%d",&people[i]);
	}
	/*for (int i = 0; i <= m+1; ++i) {
		printf("%d\n",sushiCut[i]);
	}
	for (int i = 0; i <= k; ++i) {
		printf("%d\n",people[i]);
	}*/
	int ans[2][m+2];
	int be, cur = 0;
	for (int i = 0; i <= k; ++i) {
		if (i == 0) {
			for (int j = 0; j <= m+1; ++j) {
				ans[cur][j] = 0;
			}
		}
		else {
			ans[cur][0] = 0;
			ans[cur][i] = ans[be][i-1] + people[i]*(sushiCut[i]-sushiCut[i-1]);
			for (int j = i+1; j <= m+1; ++j) {
				ans[cur][j] = max(ans[be][j-1], ans[cur][j-1]) + people[i]*(sushiCut[j]-sushiCut[j-1]);
				//printf("%d ",ans[cur][j]);
			}
		}
		//printf("\n");
		be = cur;
		cur = 1-be;
	}
	printf("%d",ans[be][m+1]);
}