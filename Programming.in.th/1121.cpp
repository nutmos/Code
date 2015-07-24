#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class stack {
    int top;
    char wongleb[100000];
public:
    void push(char c) {
        wongleb[++top] = c;
    }
    char pop() {
        char r = wongleb[top--];
        return r;
    }
    void clear() {
        top = -1;
    }
    char topElement() {
        return wongleb[top];
    }
    char topNumber() {
        return top;
    }
};

int main() {
    stack s;
    int n;
    scanf("%d",&n);
    char str[100001];
    int strIndex;
    int result[n];
    for (int i = 0; i < n; i++) {
        result[i] = 1;
        strIndex = 0;
        s.clear();
        scanf("%s",str);
        while (str[strIndex] != '\0') {
            if (str[strIndex] == '(' || str[strIndex] == '[' || str[strIndex] == '{') {
                s.push(str[strIndex]);
            }
            else if (str[strIndex] == ')') {
                if (s.topElement() == '(') {
                    s.pop();
                }
                else {
                    result[i] = 0;
                    break;
                }
            }
            else if (str[strIndex] == '}') {
                if (s.topElement() == '{') {
                    s.pop();
                }
                else {
                    result[i] = 0;
                    break;
                }
            }
            else if (str[strIndex] == ']') {
                if (s.topElement() == '[') {
                    s.pop();
                }
                else {
                    result[i] = 0;
                    break;
                }
            }
            ++strIndex;
        }
        if(s.topNumber() != -1) result[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n",(result[i] == 1)?"yes":"no");
    }
}