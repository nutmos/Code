#include <iostream>

int main(){
	int n,i,j;
	std::cin >> n;
	if (n % 2 == 0){
        for (i = 0; i < n/2; i++){
            for (j = 1; j <= n-1; j++){
                if (j == n/2 + i || j == n/2 - i) std::cout << '*';
                else std::cout << '-';
            }
            std::cout << '\n';
        }
        for (i = n/2-1; i >= 0; i--){
            for (j = 1; j <= n-1; j++){
                if (j == n/2 + i || j == n/2 - i) std::cout << '*';
                else std::cout << '-';
            }
            std::cout << '\n';
        }
	}
    else if (n % 2 != 0){
        for (i = 0; i < n/2+1; i++){
            for (j = 1; j <= n; j++){
                if (j == n/2 + i + 1 || j == n/2 - i + 1) std::cout << '*';
                else std::cout << '-';
            }
            std::cout << '\n';
        }
        for (i = n/2-1; i >= 0; i--) {
            for (j = 1; j <= n; j++){
                if (j == n/2 + i + 1 || j == n/2 - i + 1) std::cout << '*';
                else std::cout << '-';
            }
            std::cout << '\n';
        }
    }
}

