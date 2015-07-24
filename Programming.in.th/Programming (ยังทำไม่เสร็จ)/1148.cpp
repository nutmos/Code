#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int compareMax(int n1, int n2) {
	return (n1 > n2)?n1:n2;
}

int main() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int cutAt[m+2];
	cutAt[0] = 0;
	int tmp;
	for (int i = 1; i <= m; ++i) {
		scanf("%d",&cutAt[i]);
	}
	cutAt[m+1] = n;
	for (int i = m+1; i > 0; --i) {
		cutAt[i] -= cutAt[i-1];
	}
	for (int i = 0; i <= m+1; ++i) {
		printf("%d ",cutAt[i]);
	}
	int people[k+1];
	people[0] = 0;
	for (int i = 1; i <= k; ++i) {
		scanf("%d",&people[i]);
	}
	int *ans[k+1];
	ans[0] = (int *)calloc(sizeof(int), m+2);
	for (int i = 1; i <= k; ++i) {
		ans[i] = (int *)calloc(sizeof(int), m+2);
		for (int j = i; j <= m+1; ++j) {
			ans[i][j] = compareMax(ans[i-1][j-1] + (people[i] * cutAt[j]), ans[i][j-1] + (people[i] * cutAt[j]));
		}
	}
	printf("%d",ans[k][m+1]);
}