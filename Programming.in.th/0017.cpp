#include <iostream>

int main(){
	int a[4],i,j,temp,area;
	std::cin >> a[0] >> a[1] >> a[2] >> a[3];
	for (i = 0; i < 3; i++){
		for (j = i+1; j < 4; j++){
			if (a[j] > a[i]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	//std::cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << ' ';
	if ((a[0] != a[1]) && (a[1] == a[2]) && (a[2] != a[3])) area = a[0] * a[3];
	else if ((a[0] == a[1]) && (a[1] == a[2]) && (a[2] != a[3])) area = a[0] * a[3];
	else area = a[1] * a[3];
	std::cout << area;
}