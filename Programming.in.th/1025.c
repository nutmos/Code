#include <stdio.h>

int gcd(int n1, int n2) {
	if (n1%n2 == 0) {
		return n2;
	}
	else return gcd(n2, n1%n2);
}

int main() {
    //int m;
	//scanf("%d",&m);
	//int k;
	//for (k = 0; k < m; k++) {
		int n;
		scanf("%d",&n);
		unsigned long long int n1, n2;
		int i;
		for (i = 0; i < n; i++) {
			if (i == 0) {
				scanf("%llu",&n1);
			}
			else {
				scanf("%llu",&n2);
				if (n1 > n2) n1 = (n1*n2)/gcd(n1,n2);
				else n1 = (n1*n2)/gcd(n2,n1);
			}
		}
		printf("%llu\n",n1);
	//}
}