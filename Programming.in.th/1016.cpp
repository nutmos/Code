#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>

using namespace std;

int main() {
    char str[6];
    double x = 0, y = 0;
    double sqrt2 = sqrt(2);
    while (1) {
        scanf("%s",str);
        if (str[0] == '*') {
            break;
        }
        if (!(str[1] >= '0' && str[1] <= '9')) {
            if (str[1] == 'N') {
                if (str[2] == 'E') {
                    x += (double)(str[0]-'0')/sqrt2;
                    y += (double)(str[0]-'0')/sqrt2;
                }
                else if (str[2] == 'W') {
                    x -= (double)(str[0]-'0')/sqrt2;
                    y += (double)(str[0]-'0')/sqrt2;
                }
                else {
                    y += str[0]-'0';
                }
            }
            else if (str[1] == 'S') {
                if (str[2] == 'E') {
                    x += (double)(str[0]-'0')/sqrt2;
                    y -= (double)(str[0]-'0')/sqrt2;
                }
                else if (str[2] == 'W') {
                    x -= (double)(str[0]-'0')/sqrt2;
                    y -= (double)(str[0]-'0')/sqrt2;
                }
                else {
                    y -= str[0]-'0';
                }
            }
            else if (str[1] == 'E') {
                x += str[0] - '0';
            }
            else {
                x -= str[0] - '0';
            }
        }
        else if (!(str[2] >= '0' && str[2] <= '9')) {
            if (str[2] == 'N') {
                if (str[3] == 'E') {
                    x += (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                    y += (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                }
                else if (str[3] == 'W') {
                    x -= (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                    y += (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                }
                else {
                    y += (10*(str[0]-'0')+(str[1]-'0'));
                }
            }
            else if (str[2] == 'S') {
                if (str[3] == 'E') {
                    x += (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                    y -= (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                }
                else if (str[3] == 'W') {
                    x -= (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                    y -= (double)(10*(str[0]-'0')+(str[1]-'0'))/sqrt2;
                }
                else {
                    y -= (10*(str[0]-'0')+(str[1]-'0'));
                }
            }
            else if (str[2] == 'E') {
                x += (10*(str[0]-'0')+(str[1]-'0'));
            }
            else {
                x -= (10*(str[0]-'0')+(str[1]-'0'));
            }
        }
        else {
            if (str[3] == 'N') {
                if (str[4] == 'E') {
                    x += (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                    y += (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                }
                else if (str[4] == 'W') {
                    x -= (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                    y += (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                }
                else {
                    y += (100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'));
                }
            }
            else if (str[3] == 'S') {
                if (str[4] == 'E') {
                    x += (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                    y -= (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                }
                else if (str[4] == 'W') {
                    x -= (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                    y -= (double)(100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'))/sqrt2;
                }
                else {
                    y -= (100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'));
                }
            }
            else if (str[3] == 'E') {
                x += (100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'));
            }
            else {
                x -= (100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0'));
            }
        }
    }
    printf("%.3lf %.3lf\n%.3lf",x,y,sqrt(x*x + y*y));
}