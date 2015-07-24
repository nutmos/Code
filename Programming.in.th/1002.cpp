#include <iostream>

int main() {
    int n,one,ten,hundred,j;
    
    int i=0,v=0,x=0,l=0,c=0;
    
    std::cin >> n;
    
    for (j = 1; j <= n; j++) {
        one = j % 10;
        ten = (j % 100) / 10;
        hundred = j / 100;
        switch (one) {
            case 1:
                i += 1;
                break;
            case 2:
                i += 2;
                break;
            case 3:
                i += 3;
                break;
            case 4:
                i += 1;
                v += 1;
                break;
            case 5:
                v += 1;
                break;
            case 6:
                v += 1;
                i += 1;
                break;
            case 7:
                v += 1;
                i += 2;
                break;
            case 8:
                v += 1;
                i += 3;
                break;
            case 9:
                i += 1;
                x += 1;
                break;
            default:
                break;
        }
        switch (ten) {
            case 1:
                x += 1;
                break;
            case 2:
                x += 2;
                break;
            case 3:
                x += 3;
                break;
            case 4:
                x += 1;
                l += 1;
                break;
            case 5:
                l += 1;
                break;
            case 6:
                l += 1;
                x += 1;
                break;
            case 7:
                l += 1;
                x += 2;
                break;
            case 8:
                l += 1;
                x += 3;
                break;
            case 9:
                x += 1;
                c += 1;
                break;
            default:
                break;
        }
        switch (hundred) {
            case 1:
                c += 1;
                break;
            case 2:
                c += 2;
                break;
            case 3:
                c += 3;
                break;
            default:
                break;
        }
    }
    
    std::cout << i << ' ' << v << ' ' << x << ' ' << l << ' ' << c;
}