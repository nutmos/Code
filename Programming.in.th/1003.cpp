#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int a,b,c,n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = 0;
    }
    for (int a = 0; a <= 17; a++) {
        for (int b = 0; b <= 12; b++) {
            for (int c = 0; c <= 5; c++) {
                int combination = (a*6)+(b*9)+(c*20);
                if (combination <= n) {
                    array[combination-1] = 1;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == 1) {
            cout << i+1 << '\n';
            count++;
        }
    }
    if (count == 0) cout << "no\n";
}