#include <iostream>

using namespace std;

struct sudoku {
    int competitor;
    int sudoku[9][9];
};

int main() {
    int n,i,j,k,l;
    
    int sudoku_table[9][9];
    
    cin >> n;
    
    struct sudoku sudoku_contest[n],test[n];
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            cin >> sudoku_table[i][j];
        }
    }
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                cin >> sudoku_contest[k].sudoku[i][j];
            }
        }
    }
    
    int temp;
    
    for (k = 0; k < n; k++) {
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                test[k].sudoku[i][j] = sudoku_contest[k].sudoku[i][j];
            }
        }
    }
    
    for (k = 0; k < n; k++) {
        int count = 0;
        for (l = 0; l < 9; l++) {
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (test[k].sudoku[l][i] > test[k].sudoku[l][j]) {
                        temp = test[k].sudoku[l][i];
                        test[k].sudoku[l][i] = test[k].sudoku[l][j];
                        test[k].sudoku[l][j] = temp;
                    }
                }
            }
        }
        for (l = 0; l < 9; l++) {
            for (i = 1; i < 9; i++) {
                if (test[k].sudoku[l][i-1] == test[k].sudoku[l][i]) {
                    goto next;
                }
                else {
                    count++;
                }
                if (count == 9) {
                    cout << l+1 << '\n';
                }
            }
        }
        next:
            continue;
    }
    
    
    cout << "END";
}