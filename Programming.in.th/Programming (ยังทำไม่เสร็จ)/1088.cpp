//Copyright 2013 @Nutmos' Programming
//All Right Reserved
//Compile with Xcode 4.6
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    unsigned long long n,m;
    cin >> n >> m;
    // 0 = red, 1 = green, 2 = blue
    register int i,j;
    unsigned int *kingkarColor = (unsigned int *)calloc(n, sizeof(unsigned int));
    for (i = 0; i < m; i++) {
        int jim_a, jim_b;
        cin >> jim_a >> jim_b;
        for (j = jim_a-1; j < jim_b; j++) {
            kingkarColor[j]++;
        }
    }
    char foodColor;
    cin >> foodColor;
    int foodColorInt;
    switch (foodColor) {
        case 'R':
            foodColorInt = 0;
            break;
        case 'G':
            foodColorInt = 1;
            break;
        case 'B':
            foodColorInt = 2;
            break;
        default:
            break;
    }
    unsigned long long int jimCount = 0;
    for (i = 0; i < n; i++) {
        //cout << kingkar_color[i] << endl;
        kingkarColor[i] %= 3;
        if (foodColorInt == 0) {
            if (kingkarColor[i] == 1) {
                jimCount += 2;
            }
            else if (kingkarColor[i] == 2) {
                jimCount += 1;
            }
        }
        else if (foodColorInt == 1) {
            if (kingkarColor[i] == 0) {
                jimCount += 1;
            }
            else if (kingkarColor[i] == 2) {
                jimCount += 2;
            }
        }
        else if (foodColorInt == 2) {
            if (kingkarColor[i] == 0) {
                jimCount += 2;
            }
            else if (kingkarColor[i] == 1) {
                jimCount += 1;
            }
        }
    }
    cout << jimCount;
    free(kingkarColor);
}