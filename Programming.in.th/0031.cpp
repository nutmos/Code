#include <iostream>

using namespace std;

int main() {
    int count = 0;
    long a[3], temp;
    cin >> a[0] >> a[1] >> a[2];
    while (a[0] != 1 || a[1] != 1 || a[2] != 1) {
        for (int j = 0; j < 2; j++) {
            for (int k = j; k < 3; k++) {
                if (a[j] < a[k]) {
                    temp = a[k];
                    a[k] = a[j];
                    a[j] = temp;
                }
            }
        }
        a[0] = a[0] / 2;
        count++;
        //cout << a[0];
    }
    cout << count;
}