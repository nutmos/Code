//Copyright 2013 Nutmos' Studio
//Nattapong Ekdomsuk
//All Right Reserved
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int max = 0;
    int n,m,k;
    cin >> n >> m >> k;
    int *rangeX = (int *)calloc(sizeof(int), n+1);
    int *rangeY = (int *)calloc(sizeof(int), m+1);
    for (int i = 0; i < k; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int i = x-r; i <= x+r; i++) {
            //cout << "ix = " << i << endl;
            if (i >= 0 && i <= n) {
                rangeX[i]++;
                if (rangeX[i] > max) max = rangeX[i];
            }
        }
        for (int i = y-r; i <= y+r; i++) {
            //cout << "iy = " << i << endl;
            if (i >= 0 && i <= m) {
                rangeY[i]++;
                if (rangeY[i] > max) max = rangeY[i];
            }
        }
    }
    cout << max;
}