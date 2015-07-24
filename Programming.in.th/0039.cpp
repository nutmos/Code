#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void serve(int food[], bool food_tmp[], int n, int index) {
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            if (i != n-1) printf("%d ",food[i]+1);
            else printf("%d",food[i]+1);
        }
        printf("\n");
    }
    else {
        int *new_food = new int[index+1];
        bool *new_food_tmp = new bool[n];
        for (int i = 0; i < index; ++i) {
            new_food[i] = food[i];
        }
        for (int i = 0; i < n; ++i) {
            new_food_tmp[i] = food_tmp[i];
        }
        for (int i = 0; i < n; ++i) {
            if (new_food_tmp[i] == false) {
                new_food[index] = i;
                new_food_tmp[i] = true;
                serve(new_food, new_food_tmp, n, index+1);
                new_food_tmp[i] = false;
            }
        }
    }
}

int main() {
    int n,m,tmp;
    scanf("%d",&n);
    scanf("%d",&m);
    bool *cantServeFist = (bool *)calloc(sizeof(bool), n);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&tmp);
        cantServeFist[tmp-1] = true;
    }
    int *food;
    bool *food_tmp = (bool *)calloc(sizeof(int), n);
    for (int i = 0; i < n; ++i) {
        if (cantServeFist[i] == false) {
            food = new int;
            food[0] = i;
            food_tmp[i] = true;
            serve(food, food_tmp, n,1);
            food_tmp[i] = false;
        }
    }
}