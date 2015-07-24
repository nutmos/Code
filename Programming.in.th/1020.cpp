#include <iostream>
#include <string.h>

using namespace std;

void to_lower (char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int main() {
    char str[201];
    cin >> str;
    to_lower(str);
    int len = strlen(str);
    char str_temp[len+1];
    for (int i = 0; i < len; i++) {
        str_temp[i] = str[len-i-1];
    }
    str_temp[len] = '\0';
    //cout << str_temp;
    int compare = strcmp(str, str_temp);
    if (compare == 0) {
        str[len/2] = '\0';
        for (int i = 0; i < len/2; i++) {
            str_temp[i] = str[len/2 - i - 1];
        }
        str_temp[len/2] = '\0';
        int compare_1 = strcmp(str, str_temp);
        if (compare_1 == 0) {
            cout << "Double Palindrome";
        }
        else {
            cout << "Palindrome";
        }
    }
    else {
        cout << "No";
    }
}