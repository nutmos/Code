#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int *speed = (int*)calloc(sizeof(int), 2000000);
    int tmp;
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d",&tmp);
        speed[tmp-1]++;
        if (tmp > max) max = tmp;
    }
    int count = 0;
    int index = max-1;
    while (1) {
        //cout << "index = " << index << endl;
        if (speed[index] != 0) count += speed[index];
        if (count == k) {
            printf("%d",index+1);
            break;
        }
        --index;
    }
}