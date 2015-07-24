#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int n,m;
	scanf("%d %d",&m,&n);
	char str1[m+1],str2[n+1];
	scanf("%s %s",str1,str2);
	int *counting = (int *)calloc(sizeof(int), 52);
	int *count = (int *)calloc(sizeof(int),52);
	for (int i = 0; i < m; ++i) {
		if (str1[i] >= 'A' && str1[i] <= 'Z') {
			++counting[str1[i]-'A'];
		}
		else {
			++counting[str1[i]-'a'+26];
		}
		if (str2[i] >= 'A' && str2[i] <= 'Z') {
			++count[str2[i]-'A'];
		}
		else {
			++count[str2[i]-'a'+26];
		}
	}
	int method = 0;
	int countRepeat = 0;
	for (int j = 0; j < 52; ++j) {
		if (count[j] == counting[j]) ++countRepeat;
		else break;
	}
	if (countRepeat == 52) ++method;
	/*for (int i = 0; i < 52; ++i) {
		if (counting[i] > 0) printf("%d = %d ", i, counting[i]);
	}*/
	//printf("\n");
	for (int i = m; i < n; ++i) {
		countRepeat = 0;
		if (str2[i-m] >= 'A' && str2[i-m] <= 'Z') {
			--count[str2[i-m]-'A'];
		}
		else {
			--count[str2[i-m]-'a'+26];
		}
		if (str2[i] >= 'A' && str2[i] <= 'Z') {
			++count[str2[i]-'A'];
		}
		else {
			++count[str2[i]-'a'+26];
		}
		for (int j = 0; j < 52; ++j) {
			if (count[j] == counting[j]) ++countRepeat;
			else break;
		}
		//printf("countRepeat = %d\n",countRepeat);
		if (countRepeat == 52) ++method;
		//printf("test2\n");
	}
	printf("%d",method);
}