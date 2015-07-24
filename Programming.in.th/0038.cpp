#include <iostream>
#include <string.h>

using namespace std;

struct str{
    char mook[31];
};

int main() {
    int n;
    cin >> n;
    struct str string[n];
    for (int i = 0; i < n; i++) {
        cin >> string[i].mook;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cmp = strcmp(string[i].mook, string[j].mook);
            if (cmp < 0) {
                char strtmp[31];
                strcpy(strtmp, string[i].mook);
                strcpy(string[i].mook, string[j].mook);
                strcpy(string[j].mook, strtmp);
            }
        }
    }
    for (int i = n-1; i >= 0; i--) {
        int compare = strcmp(string[i].mook, string[i+1].mook);
        if (compare != 0)
            cout << string[i].mook << '\n';
    }
}