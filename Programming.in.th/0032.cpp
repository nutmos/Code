#include <iostream>

int main() {
    int n;
    
    std::cin >> n;
    
    int num[n],i = 0,temp,j;
    
loop:
    std::cin >> num[i];
    i++;
    if (i < n) goto loop;
    
    for (i = 0; i < n-1; i++) {
        for (j = i + 1; j < n; j++) {
            if (num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    if (num[0] == 0) {
        for (i = 1; i < n; i++) {
            if (num[i] != 0) {
                num[i] = -num[i];
                break;
            }
        }
        for (i = 0; i < n-1; i++) {
            for (j = i + 1; j < n; j++) {
                if (num[i] > num[j]) {
                    temp = num[i];
                    num[i] = num[j];
                    num[j] = temp;
                }
            }
        }
    }
    
    i = 0;
loop2:
    if (num[i] < 0) std::cout << -num[i];
    else std::cout << num[i];
    i++;
    if (i < n) goto loop2;
}