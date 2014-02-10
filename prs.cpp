#include <iostream>
#include <cstdio>
#include <cstdlib>
#define P 'P'
#define R 'R'
#define S 'S'

int method = 0;

void dictionary(int n, int index, int repeat, char repeatChar) {
    if (index == n-1) {
        if (repeat == 2) {
            method += 2;
        }
        else {
            method += 3;
        }
        return;
    }
    if (repeat == 3) {
        return;
    }
    if (repeat == 2) {
        switch (repeatChar) {
            case P:
                dictionary(n, index+1, 1, R);
                dictionary(n, index+1, 1, S);
                break;
            case R:
                dictionary(n, index+1, 1, P);
                dictionary(n, index+1, 1, S);
                break;
            case S:
                dictionary(n, index+1, 1, R);
                dictionary(n, index+1, 1, P);
                break;
            default:
                break;
        }
    }
    else {
        switch (repeatChar) {
            case P:
                dictionary(n, index+1, repeat+1, P);
                dictionary(n, index+1, 1, R);
                dictionary(n, index+1, 1, S);
                break;
            case R:
                dictionary(n, index+1, repeat+1, R);
                dictionary(n, index+1, 1, P);
                dictionary(n, index+1, 1, S);
                break;
            case S:
                dictionary(n, index+1, repeat+1, S);
                dictionary(n, index+1, 1, R);
                dictionary(n, index+1, 1, P);
                break;
            default:
                break;
        }
    }
}

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    char str[n+1];
    int repeat[n];
    scanf("%s",str);
    repeat[0] = 1;
    if (str[0] == S) {
        dictionary(n, 1, 1, P);
        dictionary(n, 1, 1, R);
    }
    else if (str[0] == R) {
        dictionary(n, 1, 1, P);
    }
    for (int i = 1; i < n-1; ++i) {
        if (str[i] == str[i-1]) {
            repeat[i] = repeat[i-1] + 1;
        }
        else repeat[i] = 1;
        
        if (str[i] == S) {
            if (str[i-1] == P) dictionary(n, i+1, repeat[i-1]+1, P);
            else dictionary(n, i+1, 1, P);
            if (str[i-1] == R) dictionary(n, i+1, repeat[i-1]+1, R);
            else dictionary(n, i+1, 1, R);
        }
        else if (str[i] == R) {
            if (str[i-1] == P) dictionary(n, i+1, repeat[i-1]+1, P);
            else dictionary(n, i+1, 1, P);
        }
    }
    //printf("%d\n",method);
    if (str[n-1] == R) {
        if (!(str[n-2] == P && str[n-3] == P)) {
            ++method;
        }
        ++method;
    }
    else if (str[n-1] == S) {
        if (!(str[n-2] == R && str[n-3] == R)) {
            ++method;
        }
        if (!(str[n-2] == P && str[n-3] == P)) {
            ++method;
        }
        ++method;
    }
    else method += 1;
    printf("%d",method);
}