#include <iostream>
#include <string.h>

using namespace std;

void print_row_1(int n) {
    for (int i = 0; i < n; i++) {
        if ((i+1) % 3 == 0) {
            cout << ".*..";
        }
        else {
            cout << ".#..";
        }
    }
}

void print_row_2(int n) {
    for (int i = 0; i < n; i++) {
        if ((i+1) % 3 == 0) {
            cout << "*.*.";
        }
        else {
            cout << "#.#.";
        }
    }
}

int main() {
    char ch[16];
    cin >> ch;
    int len = (int)strlen(ch);
    cout << '.';
    print_row_1(len);
    cout << "\n.";
    print_row_2(len);
    cout << "\n#";
    for (int i = 0; i < len; i++) {
        if ((i+1)%3 == 2 && i != len-1) {
            cout << "." << ch[i] << ".*";
        }
        else if (i%3==2) {
            cout << "." << ch[i] << ".*";
        }
        else {
            cout << "." << ch[i] << ".#";
        }
    }
    cout << "\n.";
    print_row_2(len);
    cout << "\n.";
    print_row_1(len);
}