#include <iostream>

using namespace std;

long double fac(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fac(n-1);
    }
}

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        printf("%.0Lf", fac(n) / (fac(n/2) * fac(n/2)));
    }
    else {
        printf("%.0Lf", 2 * (fac(n) / (fac(n/2+1) * fac(n - (n/2+1)))));
    }
}