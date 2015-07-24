#include <iostream>

using namespace std;

int main(){
	int i,integer[3],j,temp;
    char str[4];
    cin >> integer[0] >> integer[1] >> integer[2] >> str;
	for (i = 0; i < 2; i++) {
        for (j = i+1; j < 3; j++) {
            if (integer[i] > integer[j]) {
                temp = integer[i];
                integer[i] = integer[j];
                integer[j] = temp;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (str[i] == 'A') cout << integer[0];
        else if (str[i] == 'B') cout << integer[1];
        else if (str[i] == 'C') cout << integer[2];
        cout << ' ';
    }
}