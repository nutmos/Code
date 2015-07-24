#include <stdio.h>
#include <string.h>

int main() {
	int glass[3] = {1,0,0}; // 1 = ball 0 = no ball
	char str[51];
	scanf("%s",str);
	int i;
	for (i = 0; i < (int)strlen(str); i++) {
		if (str[i] == 'A') {
			char temp = glass[0];
			glass[0] = glass[1];
			glass[1] = temp;
		}
		else if (str[i] == 'B') {
			char temp = glass[1];
			glass[1] = glass[2];
			glass[2] = temp;
		}
		else if (str[i] == 'C') {
			char temp = glass[0];
			glass[0] = glass[2];
			glass[2] = temp;
		}
	}
	for (i = 0; i < 3; i++) {
		if (glass[i]) printf("%d",i+1);
	}
}