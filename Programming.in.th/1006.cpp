#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    char dice_movement[1001];
    int dice[6];
    register int i,j;
    vector<int> result_vector;
    for (i = 0; i < n; i++) {
        dice[0] = 1;
        dice[1] = 2;
        dice[2] = 3;
        dice[3] = 5;
        dice[4] = 4;
        dice[5] = 6;
        cin >> dice_movement;
        for (j = 0; dice_movement[j] != '\0'; j++) {
            if (dice_movement[j] == 'F') {
                int temp = dice[3];
                dice[3] = dice[5];
                dice[5] = temp;
                temp = dice[1];
                dice[1] = dice[5];
                dice[5] = temp;
                temp = dice[0];
                dice[0] = dice[1];
                dice[1] = temp;
            }
            else if (dice_movement[j] == 'B') {
                int temp = dice[0];
                dice[0] = dice[1];
                dice[1] = temp;
                temp = dice[1];
                dice[1] = dice[5];
                dice[5] = temp;
                temp = dice[3];
                dice[3] = dice[5];
                dice[5] = temp;
            }
            else if (dice_movement[j] == 'L') {
                int temp = dice[0];
                dice[0] = dice[4];
                dice[4] = temp;
                temp = dice[2];
                dice[2] = dice[4];
                dice[4] = temp;
                temp = dice[4];
                dice[4] = dice[5];
                dice[5] = temp;
            }
            else if (dice_movement[j] == 'R') {
                int temp = dice[0];
                dice[0] = dice[2];
                dice[2] = temp;
                temp = dice[2];
                dice[2] = dice[5];
                dice[5] = temp;
                temp = dice[4];
                dice[4] = dice[5];
                dice[5] = temp;
            }
            else if (dice_movement[j] == 'C') {
                int temp = dice[1];
                dice[1] = dice[4];
                dice[4] = temp;
                temp = dice[2];
                dice[2] = dice[4];
                dice[4] = temp;
                temp = dice[3];
                dice[3] = dice[4];
                dice[4] = temp;
            }
            else if (dice_movement[j] == 'D') {
                int temp = dice[1];
                dice[1] = dice[2];
                dice[2] = temp;
                temp = dice[2];
                dice[2] = dice[3];
                dice[3] = temp;
                temp = dice[3];
                dice[3] = dice[4];
                dice[4] = temp;
            }
        }
        result_vector.push_back(dice[1]);
    }
    for (i = 0; i < result_vector.size(); i++) {
        cout << result_vector[i] << ' ';
        //if (i != result_vector.size() - 1) cout << ' ';
    }
}