#include <iostream>

using namespace std;
int main() {
    int n;
    cin >> n;
    int tail[n];
    register int i;
    for (i = 0; i < n; i++) {
        cin >> tail[i];
    }
    int coupleTail;
    cin >> coupleTail;
    int method = 0;
    int tailCount[coupleTail+1];
    for (i = 0; i < coupleTail+1; i++) {
        tailCount[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (tail[i] <= coupleTail) tailCount[tail[i]]++;
    }
    //cout << endl;
    for (i = 0; i <= (coupleTail >> 1); i++) {
        if (i == coupleTail-i) {
            if (tailCount[i] != 1) {
                int combi = 1;
                for (register int k = tailCount[i]; k > tailCount[i]-2; k--) {
                    combi *= k;
                }
                method += combi >> 1;
            }
        }
        else method += tailCount[i] * tailCount[coupleTail-i];
        //cout << i << ' ' << method << endl;
    }
    //cout << endl;
    cout << method;
}
