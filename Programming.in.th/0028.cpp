#include <iostream>
#include <string.h>

struct team {
    char name[21];
    int point;
};

int main() {
    struct team t[4];
    
    t[0].point = 0;
    t[1].point = 0;
    t[2].point = 0;
    t[3].point = 0;
    
    int score[4][4],i,j;
    
    std::cin >> t[0].name >> t[1].name >> t[2].name >> t[3].name;
    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            std::cin >> score[i][j];
        }
    }
    
    // compare score 1,2
    if (score[0][1] > score[1][0]) {
        t[0].point += 3;
    }
    else if (score[0][1] < score[1][0]) {
        t[1].point += 3;
    }
    else {
        t[0].point += 1;
        t[1].point += 1;
    }
    
    //compare score 1,3
    if (score[0][2] > score[2][0]) {
        t[0].point += 3;
    }
    else if (score[0][2] < score[2][0]) {
        t[2].point += 3;
    }
    else {
        t[0].point += 1;
        t[2].point += 1;
    }
    
    //compare score 1,4
    if (score[0][3] > score[3][0]) {
        t[0].point += 3;
    }
    else if (score[0][3] < score[3][0]) {
        t[3].point += 3;
    }
    else {
        t[0].point += 1;
        t[3].point += 1;
    }
    
    //compare 2,3
    if (score[1][2] > score[2][1]) {
        t[1].point += 3;
    }
    else if (score[1][2] < score[2][1]) {
        t[2].point += 3;
    }
    else {
        t[1].point += 1;
        t[2].point += 1;
    }
    
    //compare 2,4
    if (score[1][3] > score[3][1]) {
        t[1].point += 3;
    }
    else if (score[1][3] < score[3][1]) {
        t[3].point += 3;
    }
    else {
        t[1].point += 1;
        t[3].point += 1;
    }
    
    //compare 3,4
    if (score[2][3] > score[3][2]) {
        t[2].point += 3;
    }
    else if (score[2][3] < score[3][2]) {
        t[3].point += 3;
    }
    else {
        t[2].point += 1;
        t[3].point += 1;
    }
    
    int gane2[4];
    
    gane2[0] = (score[0][1] + score[0][2] + score[0][3]) - (score[1][0] + score[2][0] + score[3][0]);
    gane2[1] = (score[1][0] + score[1][2] + score[1][3]) - (score[0][1] + score[2][1] + score[3][1]);
    gane2[2] = (score[2][0] + score[2][1] + score[2][3]) - (score[0][2] + score[1][2] + score[3][2]);
    gane2[3] = (score[3][0] + score[3][1] + score[3][2]) - (score[0][3] + score[1][3] + score[2][3]);
    
    int gane3[4];
    
    gane3[0] = score[0][1] + score[0][2] + score[0][3];
    gane3[1] = score[1][0] + score[1][2] + score[1][3];
    gane3[2] = score[2][0] + score[2][1] + score[2][3];
    gane3[3] = score[3][0] + score[3][1] + score[3][2];
    
    int temp;
    char tempc[21];
    
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (t[i].point < t[j].point) {
                temp = t[i].point;
                t[i].point = t[j].point;
                t[j].point = temp;
                strcpy(tempc, t[i].name);
                
                strcpy(t[i].name, t[j].name);
                
                strcpy(t[j].name, tempc);
            }
            else if (t[i].point == t[j].point) {
                if (gane2[i] != gane2[j]) {
                    if (gane2[i] < gane2[j]) {
                        temp = t[i].point;
                        t[i].point = t[j].point;
                        t[j].point = temp;
                        strcpy(tempc, t[i].name);
                        
                        strcpy(t[i].name, t[j].name);
                        
                        strcpy(t[j].name, tempc);
                    }
                }
                else {
                    if (gane3[i] < gane3[j]) {
                        temp = t[i].point;
                        t[i].point = t[j].point;
                        t[j].point = temp;
                        strcpy(tempc, t[i].name);
                        
                        strcpy(t[i].name, t[j].name);
                        
                        strcpy(t[j].name, tempc);
                    }
                }
            }
        }
    }
    
    std::cout << t[0].name << ' ' << t[0].point << '\n';
    std::cout << t[1].name << ' ' << t[1].point << '\n';
    std::cout << t[2].name << ' ' << t[2].point << '\n';
    std::cout << t[3].name << ' ' << t[3].point << '\n';
}