#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void reverse(int from, int to, int array[]) {
	while (from < to) {
		int tmp = array[from];
		array[from] = array[to];
		array[to] = tmp;
		++from;
		--to;
	}
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int sequence[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d",&sequence[i]);
	}
	char str;
	int n1, n2;
	for (int i = 0; i < m; ++i) {
		scanf("%c",&str);
		if (str == 'q') {
			scanf("%d",&n1);
			printf("%d\n",sequence[n1-1]);
		}
		else if (str == 'a') {
			scanf("%d %d",&n1,&n2);
			int tmp = sequence[n1-1];
			sequence[n1-1] = sequence[n2-1];
			sequence[n2-1] = tmp;
		}
		else if (str == 'b') {
			scanf("%d %d",&n1,&n2);
			sequence[n1-1] = n2;
		}
		else if (str == 'c') {
			scanf("%d",&n1);
			reverse(0, n1-1, sequence);
			reverse(n1, n-1, sequence);
		}
		else --i;
		//printf("i = %d\n",i);
	}
}