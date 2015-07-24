#include <iostream>
#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	vector<int> prime;
	prime.push_back(2);
	for (int i = 3; i <= 1000000; i += 2) {
		int sqrti = (int)sqrt(i);
		bool mark = false;
		for (int j = 3; j <= sqrti; ++j) {
			if (i % j == 0) {
				mark = true;
				break;
			}
		}
		if (mark == false) prime.push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int x,y,d;
		int count = 0;
		int num, countDivisor,countDivisor_tmp;
		scanf("%d %d %d",&x,&y,&d);
		for (int j = x; j <= y; ++j) {
			countDivisor = 1;
			countDivisor_tmp = 0;
			if (j != 1) {
				int num = (int)prime[0];
				int numRunner = 0;
				int j_tmp = j;
				int oldNum = 1;
				while (j_tmp != 1) {
					while (j_tmp % num != 0) {
						++numRunner;
						num = prime[numRunner];
					}
					if (num != oldNum) {
						countDivisor *= countDivisor_tmp + 1;
						countDivisor_tmp = 0;
						oldNum = num;
					}
					//printf("num = %d countDivisor_tmp = %d\n",num,countDivisor_tmp);
					++countDivisor_tmp;
					j_tmp /= num;
				}
				countDivisor *= countDivisor_tmp+1;
			}
			if (countDivisor == d) ++count;
			//printf("j = %d countDivisor = %d\n", j,countDivisor);
		}
		printf("%d\n",count);
	}
}