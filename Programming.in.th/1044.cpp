#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	int tmp;
	int sumRow[m], sumCol[n];
	for (int i = 0; i < m; ++i) {
		sumRow[i] = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&tmp);
			sumRow[i] += tmp;
			if (i == 0) {
				sumCol[j] = tmp;
			}
			else {
				sumCol[j] += tmp;
			}
		}
	}
	int increaseRow[m], increaseCol[n];
	for (int i = 0; i < m; ++i) {
		increaseRow[i] = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&tmp);
			increaseRow[i] += tmp;
			if (i == 0) {
				increaseCol[j] = tmp;
			}
			else {
				increaseCol[j] += tmp;
			}
		}
	}
	int maxValue = 0;
	//cut road by row
	int sum;
	for (int i = 0; i < m; ++i) {
		sum = 0;
		for (int j = 0; j < m; ++j) {
			if (j == i) continue;
			else if (j == i-1 || j == i+1) {
				sum += sumRow[j] + increaseRow[j];
			}
			else sum += sumRow[j];
		}
		if (sum > maxValue) maxValue = sum;
	}
	//cut road by col
	for (int i = 0; i < n; ++i) {
		sum = 0;
		for (int j = 0; j < n; ++j) {
			if (j == i) continue;
			else if (j == i-1 || j == i+1) {
				sum += sumCol[j] + increaseCol[j];
			}
			else sum += sumCol[j];
		}
		if (sum > maxValue) maxValue = sum;
	}
	printf("%d",maxValue);
}