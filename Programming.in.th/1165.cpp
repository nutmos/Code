#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long gcd(long long num1, long long num2) {
	if (num2 % num1 == 0) return num1;
	else return gcd(num2%num1, num1);
}

int main() {
	int n;
	scanf("%d",&n);
	long long num1, num2;
	scanf("%lld",&num1);
	scanf("%lld",&num2);
	if (num1 > num2) {
		long long tmp = num1;
		num1 = num2;
		num2 = tmp;
	}
	num1 = gcd(num1, num2);
	for (int i = 2; i < n; ++i) {
		scanf("%lld",&num2);
		num1 = gcd(num1, num2);
	}
	//printf("num1 = %lld\n",num1);
	int nCommonDivisor = 0;
	long long num = 1;
	while (1) {
		if (num1 / num < num) {
			break;
		}
		if (num1 % num == 0) {
			if (num * num != num1) {
				nCommonDivisor += 2;
			}
			else nCommonDivisor += 1;
		}
		++num;
	}
	printf("%d",nCommonDivisor);
}