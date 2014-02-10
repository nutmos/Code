#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define LEFT 0
#define RIGHT 1
#define DOWN 1
#define UNDOWN 0

using namespace std;

struct domino {
    int at;
    int tall;
};

int linear[1000001];

int main() {
    int n,max = 0;
    queue<int> q;
    scanf("%d",&n);
    domino *array = (domino*)calloc(sizeof(domino), n+1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d",&array[i].at,&array[i].tall);
        linear[array[i].at] = i;
        if (max < array[i].at) {
            max = array[i].at;
        }
    }
    int maxDominoDown = 0;
    int dominoDown, leftOrRight;
    bool *status;
    for (int i = 1; i <= n; ++i) {
        //Left
        status = (bool *)calloc(sizeof(bool), n+1);
        int count = 0;
        q.push(i);
        while (!q.empty()) {
            int processDomino = q.front();
            status[processDomino] = DOWN;
            q.pop();
            ++count;
            int from = array[processDomino].at;
            int to = (array[processDomino].at-array[processDomino].tall+1 < 0)?0:array[processDomino].at-array[processDomino].tall+1;
            for (int i = from; i >= to; --i) {
                if (linear[i] != 0 && status[i] != DOWN) {
                    q.push(linear[i]);
                }
            }
        }
        if (count > maxDominoDown) {
            maxDominoDown = count;
            dominoDown = i;
            leftOrRight = LEFT;
        }
        delete [] status;
        //Right
        status = (bool *)calloc(sizeof(bool), n+1);
        count = 0;
        q.push(i);
        while (!q.empty()) {
            int processDomino = q.front();
            status[processDomino] = DOWN;
            q.pop();
            ++count;
            int from = array[processDomino].at;
            int to = (array[processDomino].at+array[processDomino].tall-1 > max)?max:array[processDomino].at+array[processDomino].tall-1;
            for (int i = from; i <= to; ++i) {
                if (linear[i] != 0 && status[i] != DOWN) {
                    q.push(linear[i]);
                }
            }
        }
        if (count > maxDominoDown) {
            maxDominoDown = count;
            dominoDown = i;
            leftOrRight = RIGHT;
        }
        delete [] status;
    }
    printf("%d %c",dominoDown,(leftOrRight == LEFT)?'L':'R');
}