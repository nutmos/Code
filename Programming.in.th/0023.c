#include <stdio.h>

int main() {
    int d,m,mod;
    
    scanf("%d %d",&d,&m);
    
    if (m == 1) mod = d % 7;
    else if (m == 2) mod = (d + 31) % 7;
    else if (m == 3) mod = (d + 31 + 28) % 7;
    else if (m == 4) mod = (d + 31 + 28 + 31) % 7;
    else if (m == 5) mod = (d + 31 + 28 + 31 + 30) % 7;
    else if (m == 6) mod = (d + 31 + 28 + 31 + 30 + 31) % 7;
    else if (m == 7) mod = (d + 31 + 28 + 31 + 30 + 31 + 30) % 7;
    else if (m == 8) mod = (d + 31 + 28 + 31 + 30 + 31 + 30 + 31) % 7;
    else if (m == 9) mod = (d + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31) % 7;
    else if (m == 10) mod = (d + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7;
    else if (m == 11) mod = (d + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) % 7;
    else if (m == 12) mod = (d + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) % 7;
    
    if (mod == 1) printf("Thursday");
    else if (mod == 2) printf("Friday");
    else if (mod == 3) printf("Saturday");
    else if (mod == 4) printf("Sunday");
    else if (mod == 5) printf("Monday");
    else if (mod == 6) printf("Tuesday");
    else if (mod == 0) printf("Wednesday");
}