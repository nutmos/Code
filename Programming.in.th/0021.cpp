#include <iostream>

using namespace std;

int remove_vowel(char str[]){
    int count = 0,i,j;
    for (i = 0; str[i] != '\0'; i++){
        count++;
    }
    //std::cout << count;
    for (i = 0; i <= count; i++){
        switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                for (j = i; j <= count; j++) {
                    str[j+1] = str[j+3];
                }
                count -= 2;
                break;
            default:
                break;
        }
    }
	//printf("%d",count);
}

int main(){
    char str[100];
    
    gets(str);
    
    remove_vowel(str);
    cout << str;
    
    return 0;
}