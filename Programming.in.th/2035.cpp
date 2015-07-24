#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define EMPTY 0

using namespace std;

int abs(int n) {
    return (n>=0)?n:-n;
}

int main() {
    long long money = 0;
    int n,m;
    scanf("%d %d",&n,&m);
    long long park[n];
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&park[i]);
    }
    int *parkStatus = (int *)calloc(sizeof(int), n);
    long long car[m+1];
    car[0] = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%lld",&car[i]);
    }
    queue<int> q;
    int tmp;
    for (int i = 0; i < m<<1; ++i) {
        scanf("%d",&tmp);
        //printf("tmp = %d\n",tmp);
        if (tmp > 0) {
            bool isEmpty = false;
            for (int j = 0; j < n; ++j) {
                if (parkStatus[j] == EMPTY) {
                    parkStatus[j] = tmp;
                    money += park[j] * car[tmp];
                    //printf("car[tmp] = %d\n",car[tmp]);
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty == false) {
                q.push(tmp);
            }
        }
        else {
            int dequeue;
            for (int j = 0; j < n; ++j) {
                if (parkStatus[j] == abs(tmp)) {
                    parkStatus[j] = EMPTY;
                    dequeue = j;
                    break;
                }
            }
            if (q.empty() == false) {
                //printf("test\n");
                parkStatus[dequeue] = q.front();
                money += park[dequeue] * car[q.front()];
                //printf("1 %d\n",q.front());
                q.pop();
            }
        }
    }
    printf("%lld",money);
}