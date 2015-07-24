#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
    int n,m,tmp,rangeTo,tmpToPlus;
    scanf("%d %d",&n,&m);
    multimap<int, int> minMap;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tmp);
        tmpToPlus = 0;
        rangeTo = i-m;
        if (i > 0) {
            while (1) {
                if (minMap.begin()->second < rangeTo) {
                    minMap.erase(minMap.begin());
                }
                else {
                    tmpToPlus = minMap.begin()->first;
                    break;
                }
            }
        }
        if (i != n-1) {
            minMap.insert(pair<int, int> {tmp+tmpToPlus, i});
            /*for (multimap<int, int>::iterator it = minMap.begin(); it != minMap.end(); ++it) {
                printf("%d %d\n",it->first,it->second);
            }
            printf("\n");*/
        }
        else printf("%d",tmp+tmpToPlus);
    }
}