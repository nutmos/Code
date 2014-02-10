#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int max(int n1, int n2) {
	return (n1>n2)?n1:n2;
}

int main() {
	//0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
	//1 3 2 4 3 5 4 6
	int n;
	scanf("%d",&n);
	int sequence[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&sequence[i]);
	}
	int *ans = new int[n];
	ans[0] = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (sequence[j] < sequence[i]) {
				ans[i] = max(ans[i], ans[j]+1);
			}
		}
		//printf("ans[%d] = %d\n",i,ans[i]);
	}
	//write traceback soon...
	printf("%d",ans[n-1]);
}