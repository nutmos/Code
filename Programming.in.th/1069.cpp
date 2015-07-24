#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    struct stack {
        int end;
        char *str;
    }crystalBall;
    crystalBall.end = -1;
    crystalBall.str = (char *)malloc(n * sizeof(char));
    for (register int i = 0; i < n; i++) {
        char temp;
        cin >> temp;
        if (crystalBall.end == -1) {
            crystalBall.end++;
            crystalBall.str[crystalBall.end] = temp;
        }
        else {
            if (crystalBall.str[crystalBall.end] == temp) {
                crystalBall.end--;
            }
            else {
                crystalBall.end++;
                crystalBall.str[crystalBall.end] = temp;
            }
        }
    }
    if (crystalBall.end == -1) {
        cout << 0 << endl << "empty";
    }
    else {
        cout << crystalBall.end + 1 << endl;
        while (crystalBall.end != -1) {
            cout << crystalBall.str[crystalBall.end];
            crystalBall.end--;
        }
    }
    
}