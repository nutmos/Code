#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin >> x >> y;
    if (y % x != 0) {
        cout << y / x + 1;
    }
    else {
        cout << y / x;
    }
}