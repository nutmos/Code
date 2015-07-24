#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <list>

using namespace std;

int main() {
    int n,m,tmp;
    scanf("%d %d",&n,&m);
    list<int> wheel;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        wheel.push_back(tmp);
    }
    list<int>::iterator it,it_tmp;
    it = wheel.begin();
    int dice;
    //printf("%d",*wheel.end());
    int *competitor = (int *)calloc(sizeof(int), m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&dice);
        for (int j = 0; j < dice; ++j) {
            ++it;
            if (it == wheel.end()) {
                it = wheel.begin();
            }
        }
        //printf("%d isEnd = %s\n",*it,(it == wheel.end())?"yes":"no");
        competitor[i%m] += *it;
        it_tmp = it;
        ++it;
        if (it == wheel.end()) {
            it = wheel.begin();
        }
        wheel.erase(it_tmp);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n",competitor[i]);
    }
}