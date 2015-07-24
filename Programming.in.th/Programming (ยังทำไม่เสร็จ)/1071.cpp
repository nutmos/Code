#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

struct bombConsistOf {
    int beginX;
    int beginY;
    int endX;
    int endY;
};

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    multimap<int, int> yan;
    int x,y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&x,&y);
        yan.insert(pair<int, int> {x,y});
    }
    
    int canDestroy,canDestroyYan;
    bombConsistOf bomb;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d",&x,&y,&canDestroy);
        bomb.beginX = x-canDestroy;
        if (bomb.beginX < 0) {
            bomb.beginX = 0;
        }
        bomb.beginY = y-canDestroy;
        if (bomb.beginY < 0) {
            bomb.beginY = 0;
        }
        bomb.endX = x+canDestroy;
        if (bomb.endX > 1000) {
            bomb.endX = 1000;
        }
        bomb.endY = y+canDestroy;
        if (bomb.endY > 1000) {
            bomb.endY = 1000;
        }
        canDestroyYan = 0;
        multimap<int, int>::iterator it_before;
        for (multimap<int, int>::iterator it = yan.begin(); it != yan.end(); ) {
            if (it->first >= bomb.beginX && it->first <= bomb.endX &&
                it->second >= bomb.beginY && it->second <= bomb.endY) {
                ++canDestroyYan;
                it_before = it;
                ++it;
                yan.erase(it_before);
            }
            else {
                ++it;
            }
            if (it->first > bomb.endX) {
                break;
            }
        }
        printf("%d\n",canDestroyYan);
    }
}