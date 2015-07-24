#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void toupper(char str[]) {
    int len = (int)strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

struct city {
    char server;
    char cityName[51];
    bool isCapital;
};

int compare (const void *a, const void *b) {
    if (((city*)a)->server == ((city*)b)->server) {
        if (((city*)a)->isCapital) {
            return -1;
        }
        else if (((city*)b)->isCapital) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return ((city*)a)->server - ((city*)b)->server;
    }
}

int main() {
    int n,p,q;
    scanf("%d %d %d",&n,&p,&q);
    city *array = new city[n];
    char serverTmp[6];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s %s",serverTmp,array[i].cityName);
        toupper(array[i].cityName);
        if (serverTmp[0] >= 'a' && serverTmp[0] <= 'z') {
            serverTmp[0] -= 32;
        }
        array[i].server = serverTmp[0];
        if (array[i].server == 'D') {
            if (strcmp(array[i].cityName, "ETERNAL_CITY_MAC_ANU") == 0) array[i].isCapital = true;
            else array[i].isCapital = false;
        }
        else if (array[i].server == 'O') {
            if (strcmp(array[i].cityName, "WARRING_CITY_LUMINA_CLOTH") == 0) array[i].isCapital = true;
            else array[i].isCapital = false;
        }
        else if (array[i].server == 'T') {
            if (strcmp(array[i].cityName, "CELESTIAL_CITY_DOL_DONA") == 0) array[i].isCapital = true;
            else array[i].isCapital = false;
        }
        else if (array[i].server == 'S') {
            if (strcmp(array[i].cityName, "DUAL_CITY_BREG_EPONA") == 0) array[i].isCapital = true;
            else array[i].isCapital = false;
        }
    }
    qsort(array, n, sizeof(city), compare);
    /*for (int i = 0; i < n; ++i) {
     printf("%c %s\n",array[i].server, array[i].cityName);
     }*/
    if (!array[0].isCapital) {
        sum += q;
    }
    for (int i = 1; i < n; ++i) {
        if (strcmp(array[i].cityName, array[i-1].cityName) != 0) {
            if (array[i-1].isCapital) {
                if (array[i].server == array[i-1].server) {
                    sum += q;
                }
                else {
                    if (array[i].isCapital) {
                        sum += p;
                    }
                    else {
                        sum += p+q;
                    }
                }
            }
            else {
                if (array[i].server == array[i-1].server) {
                    sum += q<<1;
                }
                else {
                    if (array[i].isCapital) {
                        sum += p+q;
                    }
                    else {
                        sum += p+(q<<1);
                    }
                }
            }
        }
    }
    if (!array[n-1].isCapital) {
        sum += q;
    }
    printf("%d",sum);
}