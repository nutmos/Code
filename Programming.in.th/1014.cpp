#include <iostream>

using namespace std;

int main() {
    unsigned int w,h,n;
    cin >> w >> h >> n;
    struct curtainConsistOf {
        int begin;
        int length;
    }curtain[n];
    unsigned int curtainMark[w];
    register int i,j;
    for (i = 0; i < n; i++) {
        cin >> curtain[i].begin >> curtain[i].length;
    }
    for (i = 0; i < w; i++) {
        curtainMark[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < curtain[i].length; j++) {
            if (curtainMark[curtain[i].begin + j] < 2) curtainMark[curtain[i].begin + j]++;
        }
    }
    unsigned int countZero = 0, countOne = 0;
    for (i = 0; i < w; i++) {
        if (curtainMark[i] == 0) {
            countZero++;
        }
        else if (curtainMark[i] == 1) {
            countOne++;
        }
    }
    cout << countZero * h << ' ' << countOne * h;
}