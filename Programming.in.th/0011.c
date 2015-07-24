#include <stdio.h>
#include <string.h>

int main() {
    int mod[10],in[10],n=1,i,j,temp,min;
    
    for (i = 0; i < 10; i++) {
        scanf("%d",&in[i]);
    }
    
    for (i = 0; i < 10; i++){
        mod[i] = in[i] % 42;
    }
    
    for (i = 0; i < 10; i++){
        min = i;
        for (j = i+1; j < 10; j++){
            if (mod[min] > mod[j]) min = j;
        }
        temp = mod[i];
        mod[i] = mod[min];
        mod[min] = temp;
    }
    
    for (i = 0; i < 9; i++){
        if (mod[i] != mod[i+1]) n++;
    }
    
    printf("%d",n);
}