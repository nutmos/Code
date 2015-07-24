#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int element[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d",&element[i][j]);
		}
	}
	int required[m];
	for (int i = 0; i < m; ++i) {
		scanf("%d",&required[i]);
	}
	for (int i = 0; i < n; ++i) {
		int count = 0;
		for (int j = 0; j < m; ++j) {
			if (element[i][j] == required[j]) {
				++count;
			}
			else break;
		}
		if (count == m) {
			printf("%d",i+1);
			return 0;
		}
	}
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n; ++j) {
			int count = 0;
			int canCalculate = 1;
			if (canCalculate == 1) {
				for (int k = 0; k < m; ++k) {
					if (element[i][k] > required[k]) {
						canCalculate = 0;
						break;
					}
					if (element[j][k] > required[k]) break;
					if (element[i][k] + element[j][k] == required[k]) {
						++count;
					}
					else break;
				}
			}
			else break;
			if (count == m) {
				printf("%d %d",i+1,j+1);
				return 0;
			}
		}
	}
	printf("NO");
}