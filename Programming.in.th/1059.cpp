#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    char button[10][5] = {"", "", "CAB", "FDE", "IGH", "LJK", "OMN", "SPQR", "VTU", "ZWXY"};
    char text[80];
    int textIndex = 0;
    int atButton, press;
    scanf("%d %d",&atButton, &press);
    if ((atButton >= 2 && atButton <= 6) || atButton == 8) {
        text[textIndex++] = button[atButton][press%3];
    }
    else if (atButton == 7 || atButton == 9) {
        text[textIndex++] = button[atButton][press%4];
    }
    for (int i = 0; i < n-1; ++i) {
        int h, v;
        scanf("%d %d %d",&h,&v,&press);
        atButton += h + (3*v);
        if ((atButton >= 2 && atButton <= 6) || atButton == 8) {
            text[textIndex++] = button[atButton][press%3];
        }
        else if (atButton == 7 || atButton == 9) {
            text[textIndex++] = button[atButton][press%4];
        }
        else {
            if (press > textIndex) {
                textIndex = 0;
                text[textIndex] = '\0';
            }
            else {
                textIndex -= press;
                text[textIndex] = '\0';
            }
        }
    }
    if (textIndex == 0) {
        printf("null");
        return 0;
    }
    for (int i = 0; i < textIndex; ++i) {
        printf("%c",text[i]);
    }
}