#include <iostream>

int main() {
    int n,i;
    
    unsigned int max = 0;
    
    std::cin >> n;
    
    int num[n];
    
    for (i = 0; i < n; i++) {
        std::cin >> num[i];
        if (num[i] > max) max = num[i];
    }
    
    int lublai[max],lublai_max=0;
    
    for (i = 0; i < max; i++) {
        lublai[i] = 0;
    }
    
    for (i = 0; i < n; i++) {
        lublai[num[i]-1]++;
    }
    
    for (i = 0; i < max; i++) {
        if (lublai_max < lublai[i]) lublai_max = lublai[i];
    }
    
    for (i = 0; i < max; i++) {
        if (lublai[i] == lublai_max) {
            std::cout << i+1 << ' ';
        }
    }
}