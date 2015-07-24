#include <iostream>

using namespace std;

int main(){
	int a,b,c;
    cin >> a >> b >> c;
	int max = (b-a > c-b)?b-a-1:c-b-1;
	printf("%d",max);
	return 0;
}