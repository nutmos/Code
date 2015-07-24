#include <iostream>

using namespace std;

typedef struct _mountain {
	int position;
	int height;
	int rightestOfThatMountain;
}mountain;

int main() {
	int n;
	cin >> n;
	mountain mount[n];
	register int i,k,z;
	int maxHeight = 0, rightest = 0;
	for (i = 0; i < n; i++) {
		cin >> mount[i].position >> mount[i].height;
		mount[i].rightestOfThatMountain = mount[i].position+(2*mount[i].height);
		if (maxHeight < mount[i].height) maxHeight = mount[i].height;
		if (rightest < mount[i].rightestOfThatMountain) rightest = mount[i].rightestOfThatMountain;
	}
	char mountainRange[maxHeight][rightest];
	for (z = 0; z < n; z++) {
		int zPosition = mount[z].position;
		int zLength = mount[z].rightestOfThatMountain-1;
		for (i = maxHeight-1; i >= 0; i--) {
			if (i != maxHeight - 1) {
				zLength -= 1;
				zPosition += 1;
			}
			for (k = 0; k < rightest; k++) {
				if (k >= zPosition && k <= zLength) {
					mountainRange[i][k] = 'X';
				}
			}
		}
	}
    for (i = 0; i < maxHeight; i++) {
        for (k = 0; k < rightest; k++) {
            if (mountainRange[i][k] != 'X') mountainRange[i][k] = '.';
        }
    }
	for (i = 0; i < maxHeight; i++) {
		for (k = 1; k < rightest; k++) {
			if (i == 0 && mountainRange[i][k] == 'X') {
                if (mountainRange[i][k-1] != 'X' && mountainRange[i][k+1] == 'X') {
                    mountainRange[i][k] = '/';
                    mountainRange[i][k+1] = '\\';
                }
            }
            else if (i == maxHeight-1) {
                if (mountainRange[i][k] == 'X' && mountainRange[i][k-1] != 'X' && mountainRange[i][k-1] != '/' && mountainRange[i][k+1] == 'X' && mountainRange[i][k-1] != 'v') {
                    mountainRange[i][k] = '/';
                }
                if (k == rightest-1) {
                    mountainRange[i][k] = '\\';
                }
                else {
                    if (mountainRange[i][k] == 'X' && mountainRange[i][k+1] != 'X' && mountainRange[i][k+1] != '\\' && mountainRange[i][k-1] == 'X' && mountainRange[i][k-1] != 'v') {
                        mountainRange[i][k] = '\\';
                    }
                }
                if (mountainRange[i][k] == 'X' && mountainRange[i-1][k+1] == '/' && mountainRange[i-1][k-1] == '\\') {
                    //printf("in else if\n");
                    mountainRange[i][k] = 'v';
                }
            }
            else {
                if (mountainRange[i][k] == 'X' && mountainRange[i][k+1] == 'X' && mountainRange[i][k-1] != '/' && mountainRange[i][k-1] != 'X' && mountainRange[i][k-1] != 'v') {
                    mountainRange[i][k] = '/';
                }
                else if (mountainRange[i][k] == 'X' && mountainRange[i][k-1] == 'X' && mountainRange[i][k+1] != '\\' && mountainRange[i][k+1] != 'X' && mountainRange[i][k+1] != 'v') {
                    mountainRange[i][k] = '\\';
                }
                else if (mountainRange[i][k] == 'X' && mountainRange[i][k-1] == '/' && mountainRange[i][k+1] != '\\' && mountainRange[i][k+1] != 'X' && mountainRange[i][k-1] != 'v') {
                    mountainRange[i][k] = '\\';
                }
                else if (mountainRange[i][k] == 'X' && mountainRange[i-1][k+1] == '/' && mountainRange[i-1][k-1] == '\\') {
                    //printf("in else if\n");
                    mountainRange[i][k] = 'v';
                }
                if (mountainRange[i][k] == 'X' && mountainRange[i-1][k-1] == '\\' && mountainRange[i-1][k] == '.') {
                    mountainRange[i][k] = '\\';
                }
                if (mountainRange[i][k] == 'X' && mountainRange[i-1][k+1] == '/' && mountainRange[i-1][k] == '.') {
                    mountainRange[i][k] = '/';
                }
            }
            //printf("%2d,%2d",i,k);
		}
        //cout << endl;
	}
	for (i = 0; i < maxHeight; i++) {
		for (k = 1; k < rightest; k++) {
			printf("%c",mountainRange[i][k]);
		}
		printf("\n");
	}
	return 0;
}