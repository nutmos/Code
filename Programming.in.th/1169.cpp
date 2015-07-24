#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

class stack {
    int topOfStack;
    char data[200];
public:
    void clear() {
        topOfStack = -1;
    }
    void push(char c) {
        data[++topOfStack] = c;
    }
    char pop() {
        char r = data[topOfStack];
        --topOfStack;
        return r;
    }
    int topNumber() {
        return topOfStack;
    }
    char top() {
        return data[topOfStack];
    }
};

int main() {
    stack s;
    s.clear();
    char str[200];
    scanf("%s",str);
    int wantToAddWongleb = 0;
    int strIndex = 0;
    while (str[strIndex] != '\0') {
        if (str[strIndex] == '(') {
            s.push(str[strIndex]);
        }
        else if (str[strIndex] == ')') {
            if (s.topNumber() != -1) {
                s.pop();
            }
            else {
                wantToAddWongleb++;
            }
        }
        strIndex++;
    }
    wantToAddWongleb+=s.topNumber()+1;
    cout << wantToAddWongleb;
}