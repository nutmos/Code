#include <stdio.h>
#include <math.h>

double phythagorus(double a, double b){
	double po,c;
	po = (a * a) + (b * b);
	c = sqrt(po);
	return c;
}

int main(){
	double a,b,c;
	scanf("%lf %lf",&a,&b);
	c = phythagorus(a,b);
	printf("%lf",c);
	return 0;
}