#include <iostream>
#include <math.h>

using namespace std;

struct circleComponent {
    int x;
    int y;
    int r;
};

int main() {
    int n;
    cin >> n;
    unsigned long long int countCircleCottage = 0;
    register int i,j;
    struct circleComponent circle[n];
    for (i = 0; i < n; i++) {
        cin >> circle[i].x >> circle[i].y >> circle[i].r;
    }
    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            if (pow(circle[i].x-circle[j].x, 2) + pow(circle[i].y-circle[j].y, 2) < pow(circle[i].r+circle[j].r, 2)) {
                countCircleCottage++;
            }
        }
    }
    cout << countCircleCottage;
    return 0;
}