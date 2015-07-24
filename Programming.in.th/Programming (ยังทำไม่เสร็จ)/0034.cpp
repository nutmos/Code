#include <iostream>
#include <string.h>

using namespace std;

void print(int a, int b, int c, int d) {
    cout << a << ' ' << b << ' ' << c << ' ' << d;
}

int main() {
    int A,B,C,i,j,a,b,c,d;
    
    cin >> A >> B >> C;
    
    if (A != 0 && (B*B) - (4*A*C) < 0) {
        cout << "No Solution";
        return 0;
    }
    else if (A == 0 && B == 0 && C != 0) {
        cout << "No Solution";
        return 0;
    }
    else {
        for (i = 1; i <= A; i++) {
            if (A % i == 0) {
                a = i;
                c = A / i;
                for (j = 1; j <= C; j++) {
                    if (C % j == 0) {
                        b = j;
                        d = C / j;
                        if (a*d + b*c == B) {
                            goto end;
                        }
                    }
                }
            }
        }
    }
end:
    cout << a << ' ' << b << ' ' << c << ' ' << d;
}