#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int l,n,i,j,count,k;
    
    cin >> l >> n;
    
    char word[2][l+1];
    int status = 0;
    char end[l];
    for (i = 0; i < n; i++) {
        count = 0;
        if (i%2 == 0) {
            scanf("%s",word[0]);
        }
        else {
            scanf("%s",word[1]);
        }
        if (i%2 == 0 && i != 0 && status == 0) {
            //cout << "in condition" << endl;
            for (k = 0; k < l; k++) {
                if (word[0][k] != word[1][k]) {
                    count++;
                }
            }
            if (count > 2) {
                strcpy(end, word[1]);
                status = 1;
            }
        }
        if (i%2 == 1 && status == 0) {
            //cout << "in condition" << endl;
            for (k = 0; k < l; k++) {
                if (word[1][k] != word[0][k]) {
                    count++;
                }
            }
            if (count > 2) {
                strcpy(end, word[0]);
                status = 1;
            }
        }
        //cout << "count = " << count << endl;
    }
    
    /*for (i = 1; i < n; i++) {
        count = 0;
        for (j = 0; j < l; j++) {
            if (word[i][j] != word[i-1][j]) {
                count++;
            }
            if (count > 2) {
                break;
            }
        }
        if (count > 2) {
            break;
        }
    }*/
    if (status == 0) {
        if (n % 2 == 0) strcpy(end, word[1]);
        else strcpy(end, word[0]);
    }
    for (k = 0; k < l; k++) {
        cout << end[k];
    }
}