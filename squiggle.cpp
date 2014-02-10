#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    int money = 0;
    scanf("%d",&n);
    int bridge[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&bridge[i]);
    }
    for (int i = 1; i < n-1; ++i) {
        if (bridge[i-1] >= bridge[i]) {
            if (bridge[i] - bridge[i-1] + 1 >= 0) {
                money += bridge[i] - bridge[i-1] + 1;
                bridge[i-1] = bridge[i] + 1;
            }
            if (bridge[i] - bridge[i+1] + 1 >= 0) {
                money += bridge[i] - bridge[i+1] + 1;
                bridge[i+1] = bridge[i] + 1;
            }
        }
        else if (bridge[i+1] >= bridge[i]) {
            if (bridge[i] - bridge[i-1] + 1 >= 0) {
                money += bridge[i] - bridge[i-1] + 1;
                bridge[i-1] = bridge[i] + 1;
            }
            if (bridge[i] - bridge[i+1] + 1 >= 0) {
                money += bridge[i] - bridge[i+1] + 1;
                bridge[i+1] = bridge[i] + 1;
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        printf("%d\n",bridge[i]);
    }*/
    printf("%d",money);
}