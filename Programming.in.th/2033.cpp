#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct competitor {
    int id;
    int score;
    int canSolve;
};

int compare(const void *a, const void *b) {
    if (((competitor*)a)->score == ((competitor*)b)->score) {
        if (((competitor*)a)->canSolve == ((competitor*)b)->canSolve)
            return ((competitor*)a)->id - ((competitor*)b)->id;
        else
            return ((competitor*)b)->canSolve - ((competitor*)a)->canSolve;
    }
    else {
        return ((competitor*)b)->score - ((competitor*)a)->score;
    }
}

int main() {
    int n,t,p,tmp;
    scanf("%d %d %d",&n,&t,&p);
    competitor *score = (competitor *)calloc(sizeof(competitor), n);
    int *countIncorrect = (int *)calloc(sizeof(int), t);
    bool **scoreboard = new bool*[n];
    for (int i = 0; i < n; ++i) {
        score[i].id = i+1;
        scoreboard[i] = (bool *)calloc(sizeof(bool), t);
        for (int j = 0; j < t; ++j) {
            scanf("%d",&tmp);
            scoreboard[i][j] = tmp;
        }
    }
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scoreboard[j][i] == 0) {
                ++countIncorrect[i];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t; ++j) {
            if (scoreboard[i][j] == 1) {
                score[i].score += countIncorrect[j];
                score[i].canSolve += 1;
            }
        }
    }
    qsort(score, n, sizeof(competitor), compare);
    for (int i = 0; i < n; ++i) {
        //printf("%d %d\n",score[i].score,score[i].id);
        if (score[i].id == p) {
            printf("%d %d",score[i].score, i+1);
            return 0;
        }
    }
}