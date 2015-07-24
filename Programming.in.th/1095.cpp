#include <iostream>
#include <string.h>

using namespace std;

void reverse_string(int, char *);
void print_string(int, char *);

int main() {
    int row,column;
    cin >> row >> column;
    char str[row][column];
    for (int i = 0; i < row; i++) {
        cin >> str[i];
    }
    int degree;
    cin >> degree;
    //degree = 0 && degree = 360
    if (degree == 0 || degree == 360) {
        for (int i = 0; i < row; i++) {
            print_string(column, str[i]);
            cout << '\n';
        }
    }
    //degree = 90
    else if (degree == 90) {
        for (int i = 0; i < column; i++) {
            for (int j = row - 1; j >= 0; j--) {
                cout << str[j][i];
            }
            cout << '\n';
        }
    }
    //degree = 180
    else if (degree == 180) {
        for (int i = row - 1; i >= 0; i--) {
            reverse_string(column, str[i]);
            cout << '\n';
        }
    }
    //degree = 270
    else if (degree == 270) {
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                cout << str[j][column-1-i];
            }
            cout << '\n';
        }
    }
    //degree = 45
    else if (degree == 45) {
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                cout << ' ';
            }
            for (int j = 0; j < column; j++) {
                for (int k = 0; k < row; k++) {
                    if (j + k == row - i - 1) {
                        if (j == 0) cout << str[k][j];
                        else cout << ' ' << str[k][j];
                    }
                }
            }
            cout << '\n';
        }
        for (int i = row; i <= column+row-2; i++) {
            for (int j = 0; j < i - row; j++) {
                cout << ' ';
            }
            for (int j = 0; j < column; j++) {
                for (int k = 0; k < row; k++) {
                    if (j + k == i) {
                        if (j == 0) cout << str[k][j];
                        else cout << ' ' << str[k][j];
                    }
                }
            }
            cout << '\n';
        }
    }
    //degree = 135
    else if (degree == 135) {
        for (int i = 0; i < row+column-1; i++) {
            if (i >= 0 && i <= column-1) {
                for (int j = column-1; j > i; j--) {
                    cout << ' ';
                }
                for (int j = column-1; j >= 0; j--) {
                    for (int k = row-1; k >= 0; k--) {
                        if (k >= row-1-i && k-j==row-1-i) {
                            if (j == column-1 || k == row-1) {
                                cout << str[k][j];
                            }
                            else
                                cout << ' ' << str[k][j];
                        }
                    }
                }
            }
            else {
                for (int j = i-column+1; j > 0; j--) {
                    cout << ' ';
                }
                for (int j = column-1; j >= 0; j--) {
                    for (int k = row-1; k >= 0; k--) {
                        if (k >= row-1-i && k-j==row-1-i) {
                            if (j == column-1 || k == row-1) {
                                cout << str[k][j];
                            }
                            else
                                cout << ' ' << str[k][j];
                        }
                    }
                }
            }
            cout << '\n';
        }
    }
    //degree = 225
    else if (degree == 225) {
        for (int i = row - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                cout << ' ';
            }
            for (int j = 0; j < column; j++) {
                for (int k = 0; k < row; k++) {
                    if (j + k == row - i - 1) {
                        if (j == 0) cout << str[row-1-k][column-j-1];
                        else cout << ' ' << str[row-1-k][column-j-1];
                    }
                }
            }
            cout << '\n';
        }
        for (int i = row; i <= column+row-2; i++) {
            for (int j = 0; j < i - row; j++) {
                cout << ' ';
            }
            for (int j = 0; j < column; j++) {
                for (int k = 0; k < row; k++) {
                    if (j + k == i) {
                        if (j == 0) cout << str[row-1-k][column-1-j];
                        else cout << ' ' << str[row-1-k][column-1-j];
                    }
                }
            }
            cout << '\n';
        }
    }
    //degree = 315
    else if (degree == 315) {
        for (int i = 0; i < row+column-1; i++) {
            if (i >= 0 && i <= column-1) {
                for (int j = column-1; j > i; j--) {
                    cout << ' ';
                }
                for (int j = column-1; j >= 0; j--) {
                    for (int k = row-1; k >= 0; k--) {
                        if (k >= row-1-i && k-j==row-1-i) {
                            if (j == column-1 || k == row-1) {
                                cout << str[row-1-k][column-1-j];
                            }
                            else
                                cout << ' ' << str[row-1-k][column-1-j];
                        }
                    }
                }
            }
            else {
                for (int j = i-column+1; j > 0; j--) {
                    cout << ' ';
                }
                for (int j = column-1; j >= 0; j--) {
                    for (int k = row-1; k >= 0; k--) {
                        if (k >= row-1-i && k-j==row-1-i) {
                            if (j == column-1 || k == row-1) {
                                cout << str[row-1-k][column-1-j];
                            }
                            else
                                cout << ' ' << str[row-1-k][column-1-j];
                        }
                    }
                }
            }
            cout << '\n';
        }
    }
}

void reverse_string (int len, char str[]) {
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
}

void print_string (int len, char str[]) {
    for (int i = 0; i < len; i++) {
        cout << str[i];
    }
}