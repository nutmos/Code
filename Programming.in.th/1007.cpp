#include <stdio.h>

void str_reverse(char str[], int mark);

int main() {
    char str[50];
    gets(str);
    str_reverse(str, 0);
}

void str_reverse(char str[], int mark) {
    if (str[mark] != '\0') {
        str_reverse(str, mark+1);
        printf("%c",str[mark]);
    }
}