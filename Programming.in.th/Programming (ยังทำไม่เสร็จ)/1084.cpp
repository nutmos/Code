#include <iostream>

using namespace std;

int main() {
    int x,y,k;
    cin >> x >> y >> k;
    int countNumber5 = 0;
    int i;
    int tempNumber5Before = 0;
    for (i = x; i <= y; i++) {
        int temp = i;
        if (i % 5 == 0) {
            tempNumber5Before = 0;
            while (temp % 5 == 0) {
                temp = temp/5;
                tempNumber5Before++;
            }
        }
        countNumber5 += tempNumber5Before;
        //cout << i << endl;
    }
    int modK = countNumber5 % k;
    cout << modK;
}