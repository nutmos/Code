#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool specialCouple(char str1[], char str2[]) {
    if (str1[0] == str2[0]) return true;
    if (str1[1] == str2[1]) return true;
    if (str1[2] == str2[2]) return true;
    return false;
}

int main() {
    int n;
    scanf("%d",&n);
    char str[n][4];
    for (int i = 0; i < n; ++i) {
        scanf("%s",str[i]);
    }
    unsigned long long int sum = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (specialCouple(str[i], str[j])) {
                ++sum;
            }
        }
    }
    printf("%lld",sum);
}