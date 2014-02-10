#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int minOf (int a, int b) {
	return (a < b)?b:a;
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int array[2][m];
	int cur = 0;
	int next = 1;
	scanf("%d",&array[cur][0]);
	array[next][0] = array[cur][0];
	array[next][1] = array[cur][0];
	for (int i = 1; i < m-1; ++i) {
		scanf("%d",&array[cur][i]);
		array[next][i-1] = min(array[next][i-1], array[cur][i]);
		array[next][i] = min(array[next][i], array[cur][i]);
		array[next][i+1] = array[cur][i];
	}
	scanf("%d",&array[cur][m-1]);
	array[next][m-2] = min(array[next][m-2], array[cur][m-1]);
	array[next][m-1] = min(array[next][m-1], array[cur][m-1]);
	int tmp;
	cur = next;
	next = 1-next;
	for (int i = 1; i < n-1; ++i) {
		scanf("%d",&tmp);
        array[cur][0] += tmp;
		array[next][0] = array[cur][0];
		array[next][1] = array[cur][0];
		for (int j = 1; j < m-1; ++j) {
			scanf("%d",&tmp);
            array[cur][j] += tmp;
			array[next][j-1] = min(array[next][j-1], array[cur][j]);
			array[next][j] = min(array[next][j], array[cur][j]);
			array[next][j+1] = array[cur][j];
		}
		scanf("%d",&tmp);
        array[cur][m-1] += tmp;
        array[next][m-2] = min(array[next][m-2], array[cur][m-1]);
        array[next][m-1] = min(array[next][m-1], array[cur][m-1]);
        cur = next;
        next = 1-next;
	}
    scanf("%d",&tmp);
    array[cur][0] += tmp;
    array[next][0] = array[cur][0];
    array[next][1] = array[cur][0];
    for (int j = 1; j < m-1; ++j) {
        scanf("%d",&tmp);
        array[cur][j] += tmp;
        array[next][j-1] = min(array[next][j-1], array[cur][j]);
        array[next][j] = min(array[next][j], array[cur][j]);
        array[next][j+1] = array[cur][j];
    }
    scanf("%d",&tmp);
    array[cur][m-1] += tmp;
    array[next][m-2] = min(array[next][m-2], array[cur][m-1]);
    array[next][m-1] = min(array[next][m-1], array[cur][m-1]);
    int min = INT_MAX;
    for (int i = 0; i < m; ++i) {
        if (array[next][i] < min) {
            min = array[cur][i];
        }
    }
    printf("%d",min);
}