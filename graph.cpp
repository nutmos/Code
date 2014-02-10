#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

struct coordinate {
    int x;
    int y;
};

struct linear {
    int y1;
    float m;
    int x1;
};

bool isOnLinear(coordinate a, linear b) {
    if (a.y-b.y1 == b.m*(a.x-b.x1)) {
        return true;
    }
    return false;
}

bool isLinearCut(linear a, linear b) {
    if (a.m == b.m) {
        return false;
    }
    else {
        return true;
    }
}

bool isSimilar (coordinate a, coordinate b) {
    if (a.x == b.x && a.y == b.y) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int testcase;
    scanf("%d",&testcase);
    for (int II = 0; II < testcase; ++II) {
        int n;
        scanf("%d",&n);
        coordinate p[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d %d",&p[i].x,&p[i].y);
        }
        if (n == 1) {
            printf("1\n%d %d\n",p[0].x,p[0].y);
        }
        else if (n == 2) {
            printf("1\n%d %d\n%d %d\n",p[0].x,p[0].y,p[1].x,p[1].y);
        }
        coordinate ans[n];
        int ansRunner = 0;
        int maxX = 0,maxY = 0,minX = INT_MAX,minY=INT_MAX;
        coordinate maxXC, maxYC,minXC,minYC;
        for (int i = 0; i < n; ++i) {
            if (p[i].x > maxX) {
                maxX = p[i].x;
                maxXC = p[i];
            }
            if (p[i].y > maxY) {
                maxY = p[i].y;
                maxYC = p[i];
            }
            if (p[i].x < minX) {
                minX = p[i].x;
                minXC = p[i];
            }
            if (p[i].y > minY) {
                minY = p[i].y;
                minYC = p[i];
            }
        }
        ans[ansRunner++] = maxXC;
        int count = 0;
        for (int i = 0; i < ansRunner; ++i) {
            if (isSimilar(ans[ansRunner], maxYC)) {
                break;
            }
            ++count;
        }
        if (count == ansRunner) {
            ans[ansRunner++] = maxYC;
        }
        count = 0;
        for (int i = 0; i < ansRunner; ++i) {
            if (isSimilar(ans[ansRunner], minXC)) {
                break;
            }
            ++count;
        }
        if (count == ansRunner) {
            ans[ansRunner++] = minXC;
        }
        count = 0;
        for (int i = 0; i < ansRunner; ++i) {
            if (isSimilar(ans[ansRunner], minYC)) {
                break;
            }
            ++count;
        }
        if (count == ansRunner) {
            ans[ansRunner++] = minYC;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < ansRunner; ++j) {
                
            }
        }
    }
}