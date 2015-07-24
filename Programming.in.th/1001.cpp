#include <iostream>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    char ch[n][m];
    int brick[m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> brick[i];
    }
    for (int i = 0; i < m; i++) {
        while (brick[i] > 0) {
            for (int j = 0; j < n; j++) {
                if (ch[j][i] == 'O' || ch[j][i] == '#') {
                    ch[j-1][i] = '#';
                    brick[i]--;
                    break;
                }
                else if (j == n-1) {
                    ch[j][i] = '#';
                    brick[i]--;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ch[i][j];
        }
        cout << '\n';
    }
}