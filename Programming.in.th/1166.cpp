#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int maxLand = 0;
int area = 0;
int n,m;

void findMaxArea(char **land, int row, int col) {
	//printf("area = %d\n", area);
	if (land[row][col] == 'f') {
		++area;
		land[row][col] = 'x';
		if (row+1 < n) findMaxArea(land, row+1, col);
		if (row-1 >= 0) findMaxArea(land, row-1, col);
		if (col+1 < m) findMaxArea(land, row, col+1);
		if (col-1 >= 0) findMaxArea(land, row, col-1);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	char **land = new char*[n];
	for (int i = 0; i < n; ++i) {
		land[i] = new char[m+1];
		scanf("%s",land[i]);
	}
	//printf("test\n");
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (land[i][j] == '.') {
				if (i == 0) {
					if (j == 0) {
						if (land[i][j+1] != '#' && land[i+1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else if (j == m-1) {
						if (land[i][j-1] != '#' && land[i+1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else {
						if (land[i][j-1] != '#' && land[i+1][j] != '#' && land[i][j+1] != '#') {
							land[i][j] = 'f';
						}
					}
				}
				else if (i == n-1) {
					if (j == 0) {
						if (land[i][j+1] != '#' && land[i-1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else if (j == m-1) {
						if (land[i][j-1] != '#' && land[i-1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else {
						if (land[i][j-1] != '#' && land[i-1][j] != '#' && land[i][j+1] != '#') {
							land[i][j] = 'f';
						}
					}
				}
				else {
					if (j == 0) {
						if (land[i][j+1] != '#' && land[i-1][j] != '#' && land[i+1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else if (j == m-1) {
						if (land[i][j-1] != '#' && land[i-1][j] != '#' && land[i+1][j] != '#') {
							land[i][j] = 'f';
						}
					}
					else {
						if (land[i][j-1] != '#' && land[i][j+1] != '#' && land[i-1][j] != '#' && land[i+1][j] != '#') {
							land[i][j] = 'f';
						}
					}
				}
			}
		}
	}
	/*for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%c",land[i][j]);
		}
		printf("\n");
	}*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (land[i][j] == 'f') {
				area = 0;
				findMaxArea(land, i,j);
				if (area > maxLand) maxLand = area;
			}
		}
	}
	printf("%d",maxLand);
}