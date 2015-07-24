#include <iostream>

using namespace std;

int main() {
    int redApple, greenApple;
    cin >> redApple >> greenApple;
    int max = (redApple > greenApple)?redApple:greenApple;
    int min = (redApple > greenApple)?greenApple:redApple;
    int remain = -1;
    int multiply;
    while (1) {
        multiply = max/min;
        remain = max-(min*multiply);
        if (remain == 0) break;
        max = min;
        min = remain;
    }
    int gcd = min;
    //cout << min;
    for (register int i = 1; i <= min; i++) {
        if (redApple % i == 0 && greenApple % i == 0) {
            cout << i << ' ' << redApple/i << ' ' << greenApple/i << endl;
        }
    }
}