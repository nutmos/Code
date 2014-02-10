#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct co {
    int x,y;
};

bool cmpFunc(co a, co b) {
    if (a.x == b.x) {
        return a.y > b.y;
    }
    else return a.x < b.x;
}

struct cmp {
    bool operator ()(int x, int y) {
        return x > y;
    }
};

int main() {
    int n,x,y;
    scanf("%d",&n);
    multimap<int, int, cmp> coordinate;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d",&x,&y);
        coordinate.insert(pair<int, int>(x,y));
    }
    /*for (multimap<int, int>::iterator it = coordinate.begin(); it != coordinate.end(); ++it) {
     printf("%d %d\n",it->first,it->second);
     }*/
    for (multimap<int, int>::iterator it = coordinate.begin(); it != coordinate.end(); ++it) {
        ++it;
        for (multimap<int, int>::iterator it2 = it--; it2 != coordinate.end(); ) {
            if (it->first > it2->first && it->second > it2->second) {
                multimap<int, int>::iterator it_tmp = it2;
                ++it2;
                coordinate.erase(it_tmp);
            }
            else ++it2;
        }
    }
    vector<co> v;
    for (multimap<int, int>::iterator it = coordinate.begin(); it != coordinate.end(); ++it) {
        v.push_back({it->first, it->second});
    }
    sort(v.begin(), v.end(), cmpFunc);
    for (vector<co>::iterator it = v.begin(); it != v.end(); ++it) {
        printf("%d %d\n",it->x,it->y);
    }
}