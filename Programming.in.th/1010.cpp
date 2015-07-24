#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

struct coordinate {
	int row;
	int col;
};

struct alphabethAt {
	vector<coordinate> v;
};

void to_upper(char str[], int len) {
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

int main() {
	int n,m,q;
	scanf("%d %d",&n,&m);
	coordinate tmp;
	char word[n][m+1];
	alphabethAt *counting = new alphabethAt[26];
	for (int i = 0; i < n; ++i) {
		scanf("%s",word[i]);
		for (int j = 0; j < m; ++j) {
			tmp.row = i;
			tmp.col = j;
			if (word[i][j] >= 'A' && word[i][j] <= 'Z') {
				counting[word[i][j] - 'A'].v.push_back(tmp);
			}
			else {
				word[i][j] -= 32;
				counting[word[i][j] - 'A'].v.push_back(tmp);
			}
		}
	}
    /*for (int i = 0; i < n; ++i) {
        printf("%s\n",word[i]);
    }*/
	scanf("%d",&q);
	char str[16];
	int len;
	int count = 0;
	int sizeVector;
	vector<coordinate>::iterator it;
	for (int i = 0; i < q; ++i) {
		scanf("%s",str);
		len = (int)strlen(str);
        to_upper(str, len);
        //printf("%s\n",str);
		sizeVector = (int)counting[str[0] - 'A'].v.size();
		it = counting[str[0] - 'A'].v.begin();
		count = 0;
		for (int j = 0; j < sizeVector; ++j) {
			//find upper
			if (it->row - len+1 >= 0) {
				for (int k = 1; k < len; ++k) {
					if (word[it->row - k][it->col] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
			}
			if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
			//find lower
			if (it->row + len <= n) {
				for (int k = 1; k < len; ++k) {
					if (word[it->row + k][it->col] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
			}
			if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
			//find left
			if (it->col - len+1 >= 0) {
				for (int k = 1; k < len; ++k) {
					if (word[it->row][it->col - k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
			}
			if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
			//find right
			if (it->col + len <= m) {
				for (int k = 1; k < len; ++k) {
					if (word[it->row][it->col + k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
			}
			if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
            //find upleft
            if (it->col - len+1 >= 0 && it->row - len+1 >= 0) {
                for (int k = 1; k < len; ++k) {
					if (word[it->row - k][it->col - k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
            }
            if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
            //find upright
            if (it->col + len <= m && it->row - len+1 >= 0) {
                for (int k = 1; k < len; ++k) {
					if (word[it->row - k][it->col + k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
            }
            if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
            //find downleft
            if (it->col - len+1 >= 0 && it->row + len <= n) {
                for (int k = 1; k < len; ++k) {
					if (word[it->row + k][it->col - k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
            }
            if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
            count = 0;
            //find downright
            if (it->col + len <= m && it->row + len <= n) {
                for (int k = 1; k < len; ++k) {
					if (word[it->row + k][it->col + k] == str[k]) {
						++count;
					}
					else {
						break;
					}
				}
            }
            if (count == len-1) {
				printf("%d %d\n",it->row, it->col);
				break;
			}
			++it;
		}
	}
}