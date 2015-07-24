//Copyright 2013 Nutmos' Studio
//Nattapong Ekdomsuk
//All Right Reserved
#include <iostream>
#include <cstdlib>

using namespace std;

struct coordinate {
    int x;
    int y;
};

int manHuston (coordinate co1, coordinate co2) {
    return abs(co1.x-co2.x)+abs(co1.y-co2.y);
}

int main() {
    int manhustonDist = 0;
    int n;
    cin >> n;
    coordinate dist[n];
    for (int i = 0; i < n; i++) {
        cin >> dist[i].x >> dist[i].y;
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            manhustonDist += manHuston(dist[i], dist[j]);
        }
    }
    cout << manhustonDist;
}