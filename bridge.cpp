#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    int n,tmp;
    scanf("%d",&n);
    list<int> left, right;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        left.push_back(tmp);
    }
    left.sort();
    int timeUse = 0;
    list<int>::iterator it = left.begin();
    timeUse += *(++it);
    right.push_back(*left.begin());
    left.erase(left.begin());
    right.push_back(*left.begin());
    left.erase(left.begin());
    right.sort();
    /*for (list<int>::iterator it = left.begin(); it != left.end(); ++it) {
        printf("%d ",*it);
    }
    printf("\n");*/
    while (left.size() != 2 && left.size() != 3) {
        it = right.begin();
        ++it;
        timeUse += *it;
        left.push_back(*it);
        right.erase(it);
        left.sort();
        it = left.end();
        --it;
        timeUse += *it;
        right.push_back(*it);
        left.erase(it);
        --it;
        right.push_back(*it);
        left.erase(it);
        printf("%d\n",timeUse);
    }
    if (left.size() == 2) {
        timeUse += *right.begin();
        left.push_back(*right.begin());
        right.erase(right.begin());
        left.sort();
        it = left.end();
        --it;
        timeUse += *it;
        left.erase(it);
        --it;
        left.erase(it);
        timeUse += 2 * (*right.begin());
    }
    else if (left.size() == 3) {
        
    }
    printf("%d\n",timeUse);
}