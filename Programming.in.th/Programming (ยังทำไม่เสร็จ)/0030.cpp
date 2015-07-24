#include <iostream>
#include <math.h>

using namespace std;

int main() {
    char str[1000002];
    int i;
    
    cin >> str;
    
    int len = strlen(str);
    
    int num[4];
    
    for (i = 0; i < 4; i++) {
        num[i] = str[len-i-1] - 48;
    }
    
    int mod3 = num[0]%3 + num[1]%3 + num[2]%3 + num[3]%3;
    
    cout << mod3;
}