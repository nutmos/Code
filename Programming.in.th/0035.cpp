#include <iostream>

struct position {
    int x;
    int y;
};

int abs(int n) {
    if (n < 0) return -n;
    else return n;
}

int main() {
    int n;
    
    double max = 0,area;
    
    std::cin >> n;
    
    int i,j,k;
    struct position coordinate[n];
    
    for (i = 0; i < n; i++) {
        std::cin >> coordinate[i].x >> coordinate[i].y;
    }
    
    for (i = 0; i < n-2; i++) {
        for (j = i+1; j < n-1; j++) {
            for (k = j+1; k < n; k++) {
                area = abs((coordinate[i].x * coordinate[j].y) + (coordinate[j].x * coordinate[k].y) + (coordinate[k].x * coordinate[i].y) - (coordinate[i].y * coordinate[j].x) - (coordinate[j].y * coordinate[k].x) - (coordinate[k].y * coordinate[i].x));
                
                area = area/2;
                
                if (area > max) {
                    max = area;
                }
            }
        }
    }
    
    printf("%.3lf",max);
}