#include <iostream>

using namespace std;

int main() {
    int n,i,j;
    
    cin >> n;
    
    int square[n][n];
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> square[i][j];
        }
    }
    
    int sum_row[n],sum_column[n],sum_tayang[2] = {0,0};
    
    for (i = 0; i < n; i++) {
        sum_tayang[0] += square[i][i];
        sum_tayang[1] += square[i][n-1-i];
        sum_row[i] = 0;
        sum_column[i] = 0;
    }
    if (sum_tayang[0] != sum_tayang[1]) {
        goto no;
    }
    //cout << "sum_tayang[0] = " << sum_tayang[0] << " sum_tayang[1] = " << sum_tayang[1] << '\n';
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum_column[i] += square[i][j];
            sum_row[j] += square[j][i];
        }
    }
    
    /*for (int i = 0; i < n; i++) {
     cout << "sum_column[" << i << "] = " << sum_column[i] << " sum_row[" << i << "] = " << sum_row[i] << '\n';
     }*/
    
    if (sum_tayang[0] != sum_tayang[1])
        goto no;
    
    for (i = 0; i < n; i++) {
        if (sum_column[i] != sum_tayang[0] || sum_column[i] != sum_tayang[1]) {
            goto no;
        }
        if (sum_row[i] != sum_tayang[0] || sum_row[i] != sum_tayang[1]) {
            goto no;
        }
    }
    
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (square[i][j] == square[i][j+1]) {
                goto no;
            }
            if (square[i+1][j] == square[i][j]) {
                goto no;
            }
        }
    }
    
    cout << "Yes";
    return 0;
no:
    cout << "No";
}