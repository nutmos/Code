//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
#include <iostream>
#include <cstdlib>

using namespace std;

struct competitor {
    char id;
    int score;
};

void sort(competitor comp[]) {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (comp[j].score < comp[j+1].score) {
                competitor tmp = comp[j];
                comp[j] = comp[j+1];
                comp[j+1] = tmp;
            }
            if (comp[j].score == comp[j+1].score) {
                if (comp[j].id > comp[j+1].id) {
                    competitor tmp = comp[j];
                    comp[j] = comp[j+1];
                    comp[j+1] = tmp;
                }
            }
        }
    }
}

int main() {
    char voter[10001];
    competitor *comp = (competitor*)calloc(sizeof(competitor), 7);
    comp[0].id = 'A';
    comp[1].id = 'B';
    comp[2].id = 'C';
    comp[3].id = 'D';
    comp[4].id = 'E';
    comp[5].id = 'F';
    comp[6].id = 'G';
    //int status = 0;
    while (1) {
        cin >> voter;
        if (voter[0] == '!') break;
        int voterIndex = 0;
        while (voter[voterIndex] != '\0') {
            for (int i = 0; i < 7; i++) {
                if (comp[i].id == voter[voterIndex] && comp[i].score != -99999) {
                    comp[i].score++;
                    break;
                }
            }
            voterIndex++;
        }
        sort(comp);
        if (comp[6].score != -99999) {
            if (comp[6].score < comp[5].score) {
                comp[6].score = -99999;
            }
        }
        else {
            for (int k = 5; k >= 0; k--) {
                if (comp[k+1].score == -99999 && comp[k].score != -99999) {
                    if (comp[k].score < comp[k-1].score) {
                        comp[k].score = -99999;
                        break;
                    }
                }
            }
        }
        //if (status == 1) break;
        /*for (int i = 0; i < 7; i++) {
         //if (comp[i].score != -99999) {
         cout << comp[i].id << ' ' << comp[i].score << endl;
         //}
         //else break;
         }
         cout << endl;*/
    }
    int countRemain = 0;
    for (int i = 0; i < 7; i++) {
        if (comp[i].score != -99999) {
            countRemain++;
        }
        else break;
    }
    cout << countRemain << endl;
    for (int i = 0; i < 7; i++) {
        if (comp[i].score != -99999) {
            cout << comp[i].id << ' ' << comp[i].score << endl;
        }
        else break;
    }
}