//
//  main.cpp
//  CPPTest
//
//  Created by Nutmos Ekudomsuk on 6/3/55 BE.
//  Copyright (c) 2555 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int num[5];
    cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
    while (1) {
        if (num[0] == 1 && num[1] == 2 && num[2] == 3 && num[3] == 4 && num[4] == 5) {
            goto end;
        }
        else {
            if (num[0] > num[1]) {
                int temp;
                temp = num[0];
                num[0] = num[1];
                num[1] = temp;
                cout << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << '\n';
            }
            if (num[1] > num[2]) {
                int temp;
                temp = num[1];
                num[1] = num[2];
                num[2] = temp;
                cout << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << '\n';
            }
            if (num[2] > num[3]) {
                int temp;
                temp = num[2];
                num[2] = num[3];
                num[3] = temp;
                cout << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << '\n';
            }
            if (num[3] > num[4]) {
                int temp;
                temp = num[3];
                num[3] = num[4];
                num[4] = temp;
                cout << num[0] << ' ' << num[1] << ' ' << num[2] << ' ' << num[3] << ' ' << num[4] << '\n';
            }
        }
    }
end:
    return 0;
}