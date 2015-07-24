//Copyright 2013 Nattapong Ekudomsuk
//All Rights Reserved
//First compile with Xcode 4.6.1
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
    long long int n,q;
    scanf("%lld %lld",&n,&q);
    long long int *array = (long long int*)calloc(sizeof(long long int), n);
    char ch;
    long long int a,b;
    for (int i = 0; i < q; i++) {
        cin >> ch >> a >> b;
        if (ch == 'U') {
            array[a] = b;
        }
        else if (ch == 'P') {
            long long int max = 0;
            for (long long int i = a; i <= b; i++) {
                if (max < array[i]) max = array[i];
            }
            printf("%lld\n",max);
        }
    }
}