#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int number[n];
    register int i,j;
    for (i = 0; i < n; i++) {
        cin >> number[i];
    }
    int max = 0;
    int sequenceBeginAt;
    int sequenceEndAt;
    int sequenceCalculated[n];
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (j != i) {
                sequenceCalculated[j] = sequenceCalculated[j-1] + number[j];
            }
            else {
                sequenceCalculated[j] = number[j];
            }
            if (sequenceCalculated[j] > max) {
                max = sequenceCalculated[j];
                sequenceBeginAt = i;
                sequenceEndAt = j;
            }
            //cout << sequenceCalculated[i][j] << ' ';
        }
        //cout << endl;
    }
    if (max != 0) {
        for (i = sequenceBeginAt; i <= sequenceEndAt; i++) {
            cout << number[i] << ' ';
        }
        cout << endl << max;
    }
    else {
        cout << "Empty sequence";
    }
}