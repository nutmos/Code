#include <iostream>
#include <cstdio>

using namespace std;

double method;
double summary;

void recursive(int array[], int size) {
	int index1 = size>>1, index2 = size-index1;
	int array1[index1],array2[index2];
	for (int i = 0; i < size; ++i) {
		if (i < index1) {
			array1[i] = array[i];
		}
		else {
			array2[i-index1] = array[i];
		}
	}
	if (index1 > 1) recursive(array1,index1);
	if (index2 > 1) recursive(array2,index2);
	double sum = 0, sum2 = 0;
	int i1 = 0, i2 = 0;
	for (int i = 0; i < size; ++i) {
		if (i1 < index1 && i2 == index2) {
			//printf("test1\n");
			array[i] = array1[i1];
			method += sum;
			summary += (sum*array1[i1]) + sum2;
			++i1;
		}
		else if (i1 == index1 && i2 < index2) {
			//printf("test2\n");
			++sum; sum2 += array2[i2];
			array[i] = array2[i2];
			++i2;
		}
		else {
			if (array1[i1] < array2[i2]) {
				//printf("test3\n");
				array[i] = array1[i1];
				method += sum;
				summary += (sum*array1[i1]) + sum2;
				++i1;
			}
			else {
				//printf("test4\n");
				++sum; sum2 += array2[i2];
				array[i] = array2[i2];
				++i2;
			}
		}
	}
	//printf("method = %d\n",method);
}

int main() {
	int n;
	scanf("%d",&n);
	int array[n];
	int a,b;
	for (int i = 0; i < n; ++i) {
		scanf("%d %d",&a,&b);
		array[b-1] = a;
	}
	method = 0; summary = 0;
	recursive(array, n);
	/*printf("array");
	for (int i = 0; i < n; ++i) {
		printf(" %d",array[i]);
	}
	printf("\n");
	printf("method = %d\n",method);*/
	printf("%.0lf",summary);
}