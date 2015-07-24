#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>

using namespace std;

char strNum[11] = {'0','1','2','3','4','5','6','7','8','9','\0'};

char* itoa(int n) {
    if (n < 10) {
        char *str = new char[2];
        str[0] = strNum[n];
        str[1] = '\0';
        return str;
    }
    else if (n < 100) {
        char *str = new char[3];
        str[1] = strNum[n%10];
        str[0] = strNum[n/10];
        str[2] = '\0';
        return str;
    }
    else if (n < 1000) {
        char *str = new char[4];
        str[2] = strNum[n%10];
        str[1] = strNum[(n/10)%10];
        str[0] = strNum[n/100];
        str[3] = '\0';
        return str;
    }
    else if (n < 10000) {
        char *str = new char[5];
        str[3] = strNum[n%10];
        str[2] = strNum[(n/10)%10];
        str[1] = strNum[(n/100)%10];
        str[0] = strNum[n/1000];
        str[4] = '\0';
        return str;
    }
    else if (n < 100000) {
        char *str = new char[6];
        str[4] = strNum[n%10];
        str[3] = strNum[(n/10)%10];
        str[2] = strNum[(n/100)%10];
        str[1] = strNum[(n/1000)%10];
        str[0] = strNum[n/10000];
        str[5] = '\0';
        return str;
    }
    else if (n < 1000000) {
        char *str = new char[7];
        str[5] = strNum[n%10];
        str[4] = strNum[(n/10)%10];
        str[3] = strNum[(n/100)%10];
        str[2] = strNum[(n/1000)%10];
        str[1] = strNum[(n/10000)%10];
        str[0] = strNum[n/100000];
        str[6] = '\0';
        return str;
    }
    else {
        char *str = new char[8];
        str[6] = strNum[n%10];
        str[5] = strNum[(n/10)%10];
        str[4] = strNum[(n/100)%10];
        str[3] = strNum[(n/1000)%10];
        str[2] = strNum[(n/10000)%10];
        str[1] = strNum[(n/100000)%10];
        str[0] = strNum[n/1000000];
        str[7] = '\0';
        return str;
    }
}

void strrev(char str[]) {
    int len = (int)strlen(str);
    //printf("%s\n",str);
    for (int i = 0; i < len>>1; ++i) {
        char tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }
    //printf("%s\n",str);
}

bool isPalindrome(char str[]) {
    char new_str[7];
    strcpy(new_str, str);
    strrev(new_str);
    //printf("%s\n",new_str);
    if (strcmp(new_str, str) == 0) {
        return true;
    }
    else return false;
}

bool isPrime(int n) {
    if (n % 2 == 0 && n != 2) {
        return false;
    }
    int sqrtn = sqrt(n);
    for (int i = 3; i <= sqrtn; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d",&n);
    if (n < 10) {
        printf("%d",n);
        return 0;
    }
    for (int i = (n%2 == 0)?n+1:n; ; i += 2) {
        if (isPalindrome(itoa(i))) {
            if (isPrime(i)) {
                printf("%d",i);
                return 0;
            }
        }
    }
}