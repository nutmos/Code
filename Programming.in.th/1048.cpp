#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin >> k >> n;
    int str1[k], str2[k];
    int distance = 0;
    for (register int i = 0; i < n; i++) {
        //cout << "i = " << i << endl;
        //num1
        int num1 = i;
        for (register int j = 0; j < k; j++) {
            //cout << "num1 = " << num1 << endl;
            str1[k-j-1] = num1%2;
            num1 = num1 >> 1;
        }
        if (str1[k-1] == 0) {
                      distance++;
        }
        else {
             int count = 0;
             for (register int i = k-1; i >= 0; i--) {
                 if (str1[i] == 1) count++;
                 else break;
             }
             count++;
             distance += count;
        }
    }
    cout << distance;
    //scanf(" ");
}
