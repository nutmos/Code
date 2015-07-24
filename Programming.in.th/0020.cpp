#include <iostream>

using namespace std;

struct competitor {
    int score[4];
    int total_score;
};

int main() {
    struct competitor chef[5];
    
    int i,j;
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            cin >> chef[i].score[j];
        }
    }
    
    for (i = 0; i < 5; i++) {
        chef[i].total_score = 0;
    }
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            chef[i].total_score += chef[i].score[j];
        }
    }
    
    int max = 0;
    
    for (i = 0; i < 5; i++) {
        if (max < chef[i].total_score) {
            max = chef[i].total_score;
        }
    }
    
    for (i = 0; i < 5; i++) {
        if (max == chef[i].total_score) {
            cout << i+1 << ' ' << chef[i].total_score;
            break;
        }
    }
}