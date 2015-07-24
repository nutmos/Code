#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    printf("%.6lf\n%.6lf",(double)M_PI*n*n,(double)2*n*n);
}