//Copyright 2013 Nutmos' Studio
//Nattapong Ekdomsuk
//All Right Reserved
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct win {
    int speed;
    int competitor;
    int atCourse;
};

win compare(win before, win competitor) {
    if (before.speed > competitor.speed) {
        return before;
    }
    else if (before.speed < competitor.speed) {
        return competitor;
    }
    else {
        if (before.atCourse < competitor.atCourse) {
            return before;
        }
        else {
            return competitor;
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    win *winCompetitorForEachRound = (win *)calloc(sizeof(win), n);
    int *course = (int *)calloc(sizeof(int), m);
    for (int i = 0; i < n; i++) {
        int id, at, speed;
        cin >> id >> at >> speed;
        win new_competitor = {speed, id, at};
        winCompetitorForEachRound[course[at-1]] = compare(winCompetitorForEachRound[course[at-1]], new_competitor);
        course[at-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (winCompetitorForEachRound[i].competitor != 0) {
            cout << winCompetitorForEachRound[i].competitor << endl;
        }
        else break;
    }
}