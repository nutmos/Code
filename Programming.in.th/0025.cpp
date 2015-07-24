#include <iostream>
#include <string.h>

void print_multiply(int n) {
    int i;
    std::cout << '1';
    for (i = 0; i < n; i++) {
        std::cout << '0';
    }
}

void print_zero(int n){
    int i;
    for (i = 0; i < n; i++) {
        std::cout << '0';
    }
}

int main(){
	char syntax,a[100],b[100];
    int len_a, len_b,i;
	std::cin >> a >> syntax >> b;
    len_a = strlen(a);
    len_b = strlen(b);
    //std::cout << len_a << ' ' << len_b << '\n';
	if (syntax == '*') {
        print_multiply(len_a + len_b - 2);
	}
	else {
        if (len_a == len_b) {
            std::cout << '2';
            print_zero(len_a - 1);
        }
        else if (len_a > len_b) {
            std::cout << '1';
            print_zero(len_a-len_b-1);
            std::cout << b;
        }
        else if (len_a < len_b) {
            std::cout << '1';
            print_zero(len_b-len_a-1);
            std::cout << a;
        }
	}
}